/*
** save.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/export/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 26 14:42:57 2016 Walter Bonetti
** Last update Sun Jan 31 22:41:01 2016 Michel Mancier
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/tekpaint.h"

int			export_format_fox(int fd, t_tekpain *paint)
{
  t_node		*_node;
  t_layer		*cur;
  t_format_fox_header	header;
  char			name[1024];

  if (fd <= 0 || paint->layers.count <= 0)
    return (-1);
  _node = paint->layers.first;
  header.count = paint->layers.count;
  header.workzone = paint->workzone;
  my_memset(&header.offset, 0, sizeof(char) * 255);
  write(fd, &header, sizeof(t_format_fox_header));
  while (_node != NULL)
    {
      cur = _node->data;
      my_memset(name, 0, sizeof(char) * 1024);
      my_strcpy(name, cur->name);
      my_printf(1, "[Save layer]: %s\n", name);
      write(fd, name, 1024);
      write(fd, ((unsigned int *)cur->pix->pixels),
	    (header.workzone.x * header.workzone.y * sizeof(unsigned int)));
      _node = _node->next;
    }
  paint->status = 0;
  return (0);
}

int			import_format_fox(int 		fd,
					  t_tekpain 	*paint)
{
  t_format_fox_header	header;
  t_layer		*cur;
  char			name[1024];
  unsigned int		*pixels;

  if (read(fd, &header, sizeof(t_format_fox_header)) == -1)
    return (my_printf(2, "Erreur read import_format_fox\n"));
  paint->workzone = header.workzone;
  if ((pixels = bunny_malloc(sizeof(unsigned int) * header.workzone.x
		   * header.workzone.y)) == NULL)
    return (-1);
  while (header.count--)
    {
      read(fd, &name, sizeof(char) * 1024);
      layer_add(paint, layer_new(name,
				 bunny_new_pixelarray(header.workzone.x,
						      header.workzone.y), 0));
      cur = paint->current_layer->data;
      read(fd, pixels, sizeof(unsigned int) * header.workzone.x
	   * header.workzone.y);
      my_memcpy(cur->pix->pixels, pixels,
		sizeof(unsigned int) * header.workzone.x * header.workzone.y);
    }
  bunny_free(pixels);
  return (0);
}

void	paint_save(t_tekpain *paint)
{
  int	fd;
  char	path[1024];
  int	readed;

  my_printf(1, "[SAVE][FOX] Choose the name of file:\n");
  my_printf(1, "Path: ");
  readed = read(0, path, 1024);
  path[readed - 1] = 0;
  if (path[0] == 0)
    return ;
  else if (match(path, "*.fox") == 1)
    {
      fd = open(path, O_RDWR | O_CREAT, 0666);
      export_format_fox(fd, paint);
      my_printf(1, "Saved file at: %s\n", path);
      close(fd);
    }
  else
    {
      my_printf(1, "Filename seems to be invalid.\n");
      my_printf(1, "Please don't forget the '.fox' extension.\n");
      my_printf(1, "If you want to cancel, return directly.\n");
      paint_save(paint);
    }
}

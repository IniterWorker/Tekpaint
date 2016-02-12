/*
** bmp.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/export/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Jan 27 06:04:41 2016 Walter Bonetti
** Last update Sun Jan 31 23:33:08 2016 Michel Mancier
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/tekpaint.h"

void	export_format_bmp(t_fox_window 	*window,
			  t_tekpain 	*paint)
{
  char	path[1024];
  int	readed;

  my_printf(1, "[EXPORT] Choose the filename:\n");
  my_printf(1, "Path: ");
  readed = read(0, path, 1024);
  path[readed - 1] = 0;
  if (path[0] == 0)
    return ;
  else if ((match(path, "*.bmp") == 1) || (match(path, "*.png") == 1)
	   || match(path, "*.gif") == 1 || (match(path, "*.jpg") == 1))
    {
      bunny_save_pixelarray(window->buffer, path);
      my_printf(1, "File exported at: %s\n");
    }
  else
    {
      my_printf(1, "Filename seems to be invalid.\n");
      my_printf(1, "Allowed extensions are '.png', '.bmp', '.gif' & '.jpg'.\n");
      my_printf(1, "If you want to cancel, return directly.\n");
      export_format_bmp(window, paint);
    }
  paint->status = 0;
}

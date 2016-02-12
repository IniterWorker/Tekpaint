/*
** open_pixelarray.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Thu Jan 28 17:03:13 2016 Matthias RIGAUD
** Last update Thu Jan 28 17:54:36 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

t_bunny_pixelarray	*open_pixelarray()
{
  t_bunny_pixelarray	*new;
  char			*name;
  int			readed;

  name = alloca(150);
  my_printf(1, "Please tape the name (enter nothing"
	    " and press enter to quit) :\n");
  readed = read(0, name, 150);
  name[readed - 1] = 0;
  if (name[0] == 0)
    return (NULL);
  new = bunny_load_pixelarray(name);
  return (new);
}

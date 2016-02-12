/*
** negative.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Tue Jan 26 20:46:29 2016 Matthias RIGAUD
** Last update Tue Jan 26 21:06:31 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void		dark_pixelarray(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*pixel;

  pixel = pix->pixels;
  i = -1;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    pixel[i].full = RGBA_C((255 - pixel[i].argb[0]),
			   (255 - pixel[i].argb[1]),
			   (255 - pixel[i].argb[2]),
			   pixel[i].argb[3]);
}

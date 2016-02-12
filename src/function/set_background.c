/*
** set_background.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Tue Jan 19 14:11:55 2016 Matthias RIGAUD
** Last update Tue Jan 26 00:19:43 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void		set_background(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*pixels;

  pixels = pix->pixels;
  i = -1;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    if ((i / pix->clipable.buffer.width % 20 < 10 &&
	i % pix->clipable.buffer.width % 20 >= 10) ||
	(i / pix->clipable.buffer.width % 20 >= 10 &&
	i % pix->clipable.buffer.width % 20 < 10))
      pixels[i].full = 0xFFD0D0D0;
    else
      pixels[i].full = 0xFFFFFFFF;
}

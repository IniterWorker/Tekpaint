/*
** kinder_bueno.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Tue Jan 26 21:25:01 2016 Matthias RIGAUD
** Last update Tue Jan 26 22:02:08 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void		kinder_bueno_mode(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*pixels;

  pixels = pix->pixels;
  i = -1;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    pixels[i].full = ((RGBA_G(pixels[i].argb[3], pixels[i].argb[0],
			      pixels[i].argb[1], pixels[i].argb[2]) > 127) ?
		      RGBA_C(255, 255, 255, pixels[i].argb[3]) :
		      RGBA_C(0, 0, 0, pixels[i].argb[3]));
}

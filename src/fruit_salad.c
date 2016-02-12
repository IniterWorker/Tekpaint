/*
** fruit_salad.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Wed Jan 27 00:43:07 2016 Matthias RIGAUD
** Last update Wed Jan 27 00:59:26 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void		fruit_salad(t_bunny_pixelarray	*pix,
			    t_color		*color,
			    float		portion)
{
  int		i;
  t_color	*pixels;

  i = -1;
  pixels = pix->pixels;
  while (++i < pix->clipable.buffer.height * pix->clipable.buffer.width)
    pixels[i] = fox_lerp(color->full, pixels[i].full, portion);
}

/*
** blit.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Jan 25 17:50:12 2016 Walter Bonetti
** Last update Fri Jan 29 11:31:15 2016 Walter Bonetti
*/

#include "../../include/tekpaint.h"

unsigned int	alpha_blend(const unsigned int bg, const unsigned int src)
{
  unsigned int	a;
  unsigned int	rb;
  unsigned int	g;

  a = src >> 24;
  if (0 == a)
    return (bg);
  rb = (((src & 0x00ff00ff) * a) +
	((bg & 0x00ff00ff) * (0xff - a))) & 0xff00ff00;
  g  = (((src & 0x0000ff00) * a) +
	((bg & 0x0000ff00) * (0xff - a))) & 0x00ff0000;
  return (src & 0xff000000) | ((rb | g) >> 8);
}

void	paint_blit(t_bunny_pixelarray *alpha,
		   t_bunny_pixelarray *layer)
{
  int			x;
  int			y;
  t_bunny_position	pos;

  y = 0;
  while (y < alpha->clipable.clip_height && y < layer->clipable.clip_height)
    {
      x = 0;
      while (x < alpha->clipable.clip_width && x < layer->clipable.clip_width)
	{
	  pos = setpos(x, y);
	  fox_tekpixel(alpha, &pos,
		       alpha_blend(fox_getpixelxy(alpha, x, y),
				   fox_getpixelxy(layer, x, y)));
	  x++;
	}
      y++;
    }
}

void	paint_blit_old(t_bunny_pixelarray *alpha,
		       t_bunny_pixelarray *layer)
{
  t_color	cur;
  t_color	col;
  t_color	out;
  int		i;
  double	calc;

  i = 0;
  while (i < alpha->clipable.clip_height * alpha->clipable.clip_width)
    {
      cur = ((t_color *)alpha->pixels)[i];
      col = ((t_color *)layer->pixels)[i];
      if (col.argb[3] != 0)
	{
	  calc = cur.argb[3] * (255 - col.argb[3]) / (255 * 255);
	  out.argb[0] = (col.argb[0] * col.argb[3] / 255)
	      + (cur.argb[0] * calc);
	  out.argb[1] = (col.argb[1] * col.argb[3] / 255)
	      + (cur.argb[1] * calc);
	  out.argb[2] = (col.argb[2] * col.argb[3] / 255)
	      + (cur.argb[2] * calc);
	  out.argb[3] = col.argb[3] + (col.argb[3] * (255 - col.argb[3]) / 255);
	  ((t_color *)alpha->pixels)[i] = out;
	}
      i++;
    }
}

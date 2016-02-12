/*
** linesq.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Wed Jan 27 07:23:06 2016 Matthias RIGAUD
** Last update Wed Jan 27 07:37:59 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

static int      set_tab_drawline(t_bunny_position       c[4],
                                 t_bunny_position       p1,
                                 t_bunny_position       p2)
{
  c[0].x = p2.x - p1.x;
  c[0].y = p2.y - p1.y;
  c[1].x = SGN(c[0].x);
  c[1].y = SGN(c[0].y);
  c[0].x = ABS(c[0].x);
  c[0].y = ABS(c[0].y);
  c[2].x = c[0].y >> 1;
  c[2].y = c[0].x >> 1;
  c[3].x = p1.x;
  c[3].y = p1.y;
  return (0);
}

static void     draw_line_octan(t_bunny_pixelarray      *pix,
                                t_bunny_position        c[4],
				t_color			*color,
				t_bunny_position	*size)
{
  int           i;

  i = 0;
  while (i < c[0].x)
    {
      c[2].y = c[2].y + c[0].y;
      if (c[2].y >= c[0].x)
        {
          c[2].y = c[2].y - c[0].x;
          c[3].y = c[3].y + c[1].y;
        }
      c[3].x = c[3].x + c[1].x;
      fox_draw_rectangle_fill(pix, c[3], *size, *color);
      i = i + 1;
    }
}

static void     draw_line_octan_inf(t_bunny_pixelarray  *pix,
                                    t_bunny_position    c[4],
                                    t_color		*color,
				    t_bunny_position	*size)
{
  int           i;

  i = 0;
  while (i < c[0].y)
    {
      c[2].x = c[2].x + c[0].x;
      if (c[2].x >= c[0].y)
        {
          c[2].x = c[2].x - c[0].y;
          c[3].x = c[3].x + c[1].x;
        }
      c[3].y = c[3].y + c[1].y;
      fox_draw_rectangle_fill(pix, c[3], *size, *color);
      i = i + 1;
    }
}

void	linesq(t_bunny_pixelarray	*pix,
	       t_ext			*ext,
	       t_color			*color,
	       t_bunny_position		*size)
{
  t_bunny_position      c[4];

  set_tab_drawline(c, ext->fist, ext->second);
  fox_draw_rectangle_fill(pix, ext->fist, *size, *color);
  if (c[0].x >= c[0].y)
    draw_line_octan(pix, c, color, size);
  else
    draw_line_octan_inf(pix, c, color, size);
}

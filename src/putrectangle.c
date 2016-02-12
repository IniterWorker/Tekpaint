/*
** putrectangle.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Sat Jan 30 14:38:41 2016 Matthias RIGAUD
** Last update Sun Jan 31 06:45:36 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void			draw_bord(t_bunny_pixelarray	*pix,
				  t_tekpain		*paint,
				  t_bunny_position	*size,
				  t_color		*color)
{
  t_bunny_position	pos;

  pos.y = paint->f_pos.y - 1;
  while (++pos.y < paint->f_pos.y + size->y)
    {
      pos.x = paint->f_pos.x - 1;
      while (++pos.x < paint->f_pos.x + size->x)
	if (pos.x - paint->f_pos.x < paint->size ||
	    pos.x - paint->f_pos.x - size->x >= -paint->size ||
	    pos.y - paint->f_pos.y < paint->size ||
	    pos.y - paint->f_pos.y - size->y >= -paint->size)
	  fox_tekpixel(pix, &pos, color->full);
    }
}

void		draw_rec(t_bunny_pixelarray	*pix,
			 t_tekpain		*paint,
			 t_bunny_position	*size)
{
  t_color	color;

  color.full = paint->current_color;
  if (paint->opt == 1)
    fox_draw_rectangle_fill(pix, paint->f_pos, *size, color);
  else if (paint->opt == 2)
    draw_bord(pix, paint, size, &color);
  else if (paint->opt == 3)
    {
      fox_draw_rectangle_fill(pix, paint->f_pos, *size, color);
      color.full = paint->tmp_color[1];
      draw_bord(pix, paint, size, &color);
    }
}

void			my_putrectangle(t_bunny_pixelarray	*pix,
					t_window_mouse		*mouse,
					t_tekpain		*paint)
{
  t_bunny_position	size;

  if (mouse->state == GO_DOWN && paint->line_begin == 1)
      {
	paint->line_begin = 2;
	paint->f_pos.x = mouse->pos->x;
	paint->f_pos.y = mouse->pos->y;
      }
  else if (mouse->state == GO_UP && paint->line_begin == 2)
    paint->line_begin = 0;
  else if (mouse->state == GO_UP && paint->line_begin == 3)
    paint->line_begin = 1;
  else if (mouse->state == GO_DOWN && !paint->line_begin)
    {
	paint->line_begin = 3;
	size.x = VA(paint->f_pos.x - mouse->pos->x);
	size.y = VA(paint->f_pos.y - mouse->pos->y);
	paint->f_pos.x = (mouse->pos->x < paint->f_pos.x) ?
	  (mouse->pos->x) : (paint->f_pos.x);
	paint->f_pos.y = (mouse->pos->y < paint->f_pos.y) ?
	  (mouse->pos->y) : (paint->f_pos.y);
	draw_rec(pix, paint, &size);
    }
}

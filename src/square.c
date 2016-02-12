/*
** square.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Wed Jan 27 06:57:37 2016 Matthias RIGAUD
** Last update Fri Jan 29 17:49:36 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void		square(t_window_mouse		*mouse,
		       t_bunny_pixelarray	*pix,
		       t_tekpain		*paint)
{
  t_bunny_position	pos;
  t_bunny_position	size;
  t_color		color;
  t_ext			ext;

  if (mouse->state == GO_DOWN && (size.x = paint->size * 2) &&
      (size.y = paint->size * 2))
    {
      pos.x = mouse->pos->x - paint->size;
      pos.y = mouse->pos->y - paint->size;
      color.full = paint->current_color;
      if (paint->is_start)
	fox_draw_rectangle_fill(pix, pos, size, color);
      else
        {
	  ext.fist.x = mouse->prev.x - paint->size;
	  ext.fist.y = mouse->prev.y - paint->size;
	  ext.second.x = mouse->pos->x - paint->size;
	  ext.second.y = mouse->pos->y - paint->size;
          linesq(pix, &ext, &color, &size);
        }
      mouse->prev.x = mouse->pos->x;
      mouse->prev.y = mouse->pos->y;
      (paint->status = 1) ? (paint->is_start = 0) : (paint->is_start = 0);
    }
}

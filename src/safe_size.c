/*
** safe_size.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 28 11:21:47 2016 Walter Bonetti
** Last update Fri Jan 29 21:59:06 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

int			paint_size_mode(t_fox_window	*win,
					t_tekpain	*paint,
					int 		add_value)
{
  t_bunny_position	pos;

  pos = setpos(win->buffer->clipable.clip_width / 2,
	 win->buffer->clipable.clip_height / 2);
  if (paint->size + add_value > 0)
    {
      paint->size += add_value;
      fox_draw_filled_cricle(win->buffer, &pos,
			     paint->current_color, paint->size);
      paint->status = 1;
    }
  else
    {
      paint->size = 1;
    }
  return (0);
}

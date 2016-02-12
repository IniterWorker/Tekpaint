/*
** function_draw.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Jan 27 07:51:23 2016 Walter Bonetti
** Last update Sun Jan 31 11:07:29 2016 Michel Mancier
*/

#include "../include/tekpaint.h"

void	paint_line(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint)
{
  my_putline(cur->pix, mouse, paint);
  if (mouse->state == 0)
    {
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_rect(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint)
{
  my_putrectangle(cur->pix, mouse, paint);
  if (mouse->state == 0)
    {
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void		paint_spray(t_window_mouse 	*mouse,
			    t_layer		*cur,
			    t_tekpain		*paint)
{
  t_color	color;

  color.full = paint->current_color;
  if (mouse->state == 0)
    {
      rackaille(cur->pix, mouse->pos, &color, paint->size);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_elips(t_window_mouse 	*mouse,
		    t_layer		*cur,
		    t_tekpain		*paint)
{
  elipse(cur->pix, mouse, paint);
  if (mouse->state == 0)
    {
      paint->status = 1;
      cur->is_modified = 1;
    }
}

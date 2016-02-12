/*
** function_draw_plus.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Jan 27 08:22:53 2016 Walter Bonetti
** Last update Fri Jan 29 17:58:05 2016 Matthias RIGAUD
*/

#include "../include/tekpaint.h"

void	paint_negatif(t_window_mouse 	*mouse,
		      t_layer		*cur,
		      t_tekpain		*paint)
{
  if (mouse->state == 0)
    {
      dark_pixelarray(cur->pix);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_kinder(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint)
{
  if (mouse->state == 0)
    {
      kinder_bueno_mode(cur->pix);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_blur(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint)
{
  if (mouse->state == 0)
    {
      blurp(cur->pix, 5);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_gris(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint)
{
  if (mouse->state == 0)
    {
      fox_mod_grey(cur->pix);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void	paint_salade(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint)
{
  t_color	color;

  color.full = paint->current_color;
  if (mouse->state == 0)
    {
      fruit_salad(cur->pix, &color, 0.5);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

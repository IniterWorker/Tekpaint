/*
** draw.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Jan 25 17:25:31 2016 Walter Bonetti
** Last update Sun Jan 31 02:37:22 2016 Matthias RIGAUD
*/

#include "../include/tekpaint.h"

void	fox_draw_filled_cricle(t_bunny_pixelarray 	*pix,
			       t_bunny_position 	*pos,
			       unsigned int		color,
			       int 			radius)
{
  int	x;
  int	y;
  int	height;
  t_bunny_position	n_pos;

  x = -radius;
  while (x < radius)
    {
      height = (int)sqrt(radius * radius - x * x);
      y = -height;
      while (y < height)
	{
	  n_pos.x = x + pos->x;
	  n_pos.y = y + pos->y;
	  fox_tekpixel(pix, &n_pos, color);
	  y++;
	}
      x++;
    }
}

void	paint_pincile_draw(t_window_mouse 	*mouse,
			   t_layer		*cur,
			   t_tekpain		*paint)
{
  t_ext	ext;

  if (paint->forme == 0)
    {
      square(mouse, cur->pix, paint);
      return ;
    }
  if (mouse->state == 0)
    {
      if (paint->is_start)
	{
	  fox_draw_filled_cricle(cur->pix, (t_bunny_position *)mouse->pos,
				   paint->current_color, paint->size);
	}
      else
	{
	  ext.fist = mouse->prev;
	  ext.second = *mouse->pos;
	  line(cur->pix, &ext, paint->current_color, paint->size);
	}
      mouse->prev = *mouse->pos;
      paint->status = 1;
      (cur->is_modified = 1) ? (paint->is_start = 0) : (paint->is_start = 0);
    }
}

void	paint_bucket(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint)
{
  t_color	color;

  color.full = paint->current_color;
  if (mouse->state == 0)
    {
      fill_flood(cur->pix, (t_bunny_position *)mouse->pos, &color,
		 &paint->status);
      paint->status = 1;
      cur->is_modified = 1;
    }
}

void		paint_gomme(t_window_mouse 	*mouse,
			    t_layer		*cur,
			    t_tekpain		*paint)
{
  t_color	color;

  color.full = paint->current_color;
  paint->current_color = RGBA_C(0, 0, 0, 0);
  paint_pincile_draw(mouse, cur, paint);
  paint->current_color = color.full;
}

void		paint_pipette(t_window_mouse 	*mouse,
			      t_layer		*cur,
			      t_tekpain		*paint)
{
  if (mouse->state == GO_DOWN)
    paint->current_color = ((unsigned int *)
			    (cur->pix->pixels))[getxy(mouse->pos->x,
						      mouse->pos->y,
						      cur->pix)];
  color_swich(paint);
  color_swich(paint);
}

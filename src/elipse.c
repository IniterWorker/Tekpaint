/*
** elipse.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Sun Jan 31 03:37:49 2016 Matthias RIGAUD
** Last update Sun Jan 31 15:20:56 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void			draw_elipse(t_bunny_pixelarray	*pix,
				    t_bunny_position	*top,
				    t_bunny_position	*size,
				    t_color		*color)
{
  double                i;
  t_bunny_position      *pos;
  t_bunny_position	center;

  i = 0;
  pos = alloca(2);
  center.x = top->x + size->x / 2;
  center.y = top->y + size->y / 2;
  while (i < 180)
    {
      pos[0].x = center.x + cos((360 - i)
				/ 180.0f * M_PI) * (double)(size->x / 2);
      pos[0].y = center.y + sin((360 - i)
				/ 180.0f * M_PI) * (double)(size->y / 2);
      pos[1].x = center.x + cos(i / 180.0f * M_PI) * (double)(size->x / 2);
      pos[1].y = center.y + sin(i / 180.0f * M_PI) * (double)(size->y / 2);
      fox_draw_line(pix, pos, color->full);
      i += 0.1;
    }
}

void			draw_elipse_bord(t_bunny_pixelarray	*pix,
					 t_tekpain			*paint,
					 t_bunny_position	*size,
					 t_color		*color)
{
  double                i;
  int			j;
  t_bunny_position      *pos;

  j = -1;
  pos = alloca(2);
  pos[0].x = paint->f_pos.x + size->x / 2;
  pos[0].y = paint->f_pos.y + size->y / 2;
  while (++j < paint->size)
    {
      i = 0;
      while (i < 360)
	{
	  pos[1].x = pos[0].x + cos(i / 180.0f * M_PI) * (double)(size->x / 2);
	  pos[1].y = pos[0].y + sin(i / 180.0f * M_PI) * (double)(size->y / 2);
	  fox_tekpixel(pix, &pos[1], color->full);
	  i += 0.1;
	}
      size->x--;
      size->y--;
      if (size->x < 0 || size->y < 0)
	return ;
    }
}

void		gest_elipse(t_bunny_pixelarray	*pix,
			    t_tekpain		*paint,
			    t_bunny_position	*size)
{
  t_color	color;

  color.full = paint->current_color;
  if (paint->opt == 1)
    draw_elipse(pix, &paint->f_pos, size, &color);
  else if (paint->opt == 2)
    draw_elipse_bord(pix, paint, size, &color);
  else if (paint->opt == 3)
    {
      draw_elipse(pix, &paint->f_pos, size, &color);
      color.full = paint->tmp_color[1];
      draw_elipse_bord(pix, paint, size, &color);
    }
}

void			elipse(t_bunny_pixelarray	*pix,
			       t_window_mouse    	*mouse,
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
	gest_elipse(pix, paint, &size);
    }
}

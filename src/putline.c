/*
** putline.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Wed Jan 27 06:01:48 2016 Matthias RIGAUD
** Last update Sat Jan 30 16:20:20 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void	my_putline(t_bunny_pixelarray	*pix,
		   t_window_mouse	*mouse,
		   t_tekpain		*paint)
{
  if (mouse->state == GO_DOWN && paint->line_begin == 1)
      {
	paint->line_begin = 2;
	paint->ext_line.fist.x = mouse->pos->x;
	paint->ext_line.fist.y = mouse->pos->y;
      }
  else if (mouse->state == GO_UP && paint->line_begin == 2)
    paint->line_begin = 0;
  else if (mouse->state == GO_UP && paint->line_begin == 3)
    paint->line_begin = 1;
  else if (mouse->state == GO_DOWN && !paint->line_begin)
    {
	paint->line_begin = 3;
	paint->ext_line.second.x = mouse->pos->x;
	paint->ext_line.second.y = mouse->pos->y;
	line(pix, &paint->ext_line, paint->current_color, paint->size);
    }
}

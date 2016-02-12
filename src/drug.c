/*
** drug.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Sun Jan 31 14:52:28 2016 Matthias RIGAUD
** Last update Sun Jan 31 22:19:17 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void	drug(t_tekpain	*paint)
{
  if (!paint->is_drug)
    {
      bunny_sound_stop(paint->smoke_weed_every_day);
      return ;
    }
  if (paint->is_drug == 1)
    {
      bunny_sound_volume(paint->smoke_weed_every_day, 100);
      bunny_sound_play(paint->smoke_weed_every_day);
      bunny_sound_loop(paint->smoke_weed_every_day, true);
      paint->is_drug = 2;
    }
  paint->current_color = rand() | BLACK;
  paint->tmp_color[1] = rand() | BLACK;
  paint->size = 1 + rand() % 30;
  tekpaint_menu_draw_default(paint);
}

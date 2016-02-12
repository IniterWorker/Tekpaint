/*
** init_tekpain.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Jan 25 19:24:46 2016 Walter Bonetti
** Last update Sun Jan 31 23:12:11 2016 Matthias RIGAUD
*/

#include "../include/tekpaint.h"

t_tekpain	*tekpain_new(t_bunny_position workzone)
{
  t_tekpain	*new;

  if ((new = bunny_malloc(sizeof(t_tekpain))) == NULL)
    return (NULL);
  new->status = 1;
  new->type = 1;
  new->tmp_color[0] = BLACK;
  new->tmp_color[1] = WHITE;
  new->current_color = new->tmp_color[0];
  new->workzone = workzone;
  new->menu_pos.y = 581;
  new->menu_pos.x = 0;
  new->menu_toggle = 0;
  new->capture = 0;
  new->one_click = 0;
  new->alpha = 255;
  new->is_start = 1;
  new->forme = 1;
  new->line_begin = 1;
  new->size = 10;
  new->opt = 1;
  new->is_drug = 0;
  new->smoke_weed_every_day = bunny_load_music("resources/smoke_weed.ogg");
  new->trans_lvl = 255;
  return (new);
}

void		tekpaint_menu_draw_default(t_tekpain *paint)
{
  t_color	color;

  color.full = paint->current_color;
  fox_draw_rectangle_fill(paint->menu, setpos(87, 123), setpos(30, 30),
			  color);
  color.full = paint->tmp_color[1];
  fox_draw_rectangle_fill(paint->menu, setpos(127, 139), setpos(30, 30),
			  color);
}

void	tekpaint_next_load(t_tekpain *paint)
{
  char	path[1024];

  path[0] = '\n';
  while (path[0] != '\n' && path[0] != 'y' && path[0] != 'n')
    {
      my_printf(1, "[Fox] Close ? (y/n)\n");
      if (path[0] == 'n')
	return ;
    }
  read(0, path, 1024);
  if (path[0] != '\n')
    {
      tekpaint_close(paint);
    }
}

void		tekpaint_close(t_tekpain *paint)
{
  if (paint == NULL)
    return ;
  my_printf(1, "[layer][list] free all\n");
  list_destructeur(&paint->layers);
  list_destructeur(&paint->mouse_history);
}

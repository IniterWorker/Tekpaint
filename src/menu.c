/*
** menu.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Jan 27 21:46:36 2016 Walter Bonetti
** Last update Sun Jan 31 11:00:39 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

int		menu_btn(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[5];
  void	(*pt_function[5])(t_fox_window *win, t_tekpain *paint);

  if (!(paint->one_click) || (!(block = 0) && !paint->menu_toggle))
    return (0);
  i = -1;
  btns[0] = set_btn(-1, setpos(0, 638), setpos(230, 130));
  btns[1] = set_btn(-2, setpos(230, 638), setpos(360, 130));
  btns[2] = set_btn(-3, setpos(580, 658), setpos(200, 100));
  btns[3] = set_btn(-4, setpos(840, 638), setpos(184, 130));
  btns[4] = set_btn(-5, setpos(0, 578), setpos(1024, 60));
  while (i++ < 4)
    if (win->mouse.state == GO_DOWN && in_box_button(setpos(win->mouse.pos->x,
	win->mouse.pos->y), btns[i]))
      block = ABS(btns[i].type);
  pt_function[1] = &menu_block_save;
  pt_function[2] = &menu_block_outils;
  pt_function[3] = &menu_block_palette;
  pt_function[4] = &menu_block_settings;
  pt_function[5] = &menu_block_plus;
  if (block > 0)
    (pt_function[block])(win, paint);
  return (0);
}

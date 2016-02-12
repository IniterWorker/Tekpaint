/*
** menu_block_plus.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Jan 31 10:55:30 2016 Walter Bonetti
** Last update Sun Jan 31 14:51:47 2016 Matthias RIGAUD
*/

#include "../include/tekpaint.h"

void		block_1(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[2];

  i = 0;
  btns[0] = set_btn(1, setpos(21, 595), setpos(40, 40));
  btns[1] = set_btn(2, setpos(168, 595), setpos(40, 40));
  while (i < 2)
    {
      if (in_box_button(setpos(win->mouse.pos->x,
		       win->mouse.pos->y), btns[i]))
	block = btns[i].type;
      i++;
    }
  if (block == 1)
    load_bmp_layer(paint);
  if (block == 2)
    return ;
}

void		block_2(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[5];

  i = -1;
  block = 0;
  btns[0] = set_btn(1, setpos(236, 595), setpos(40, 40));
  btns[1] = set_btn(2, setpos(296, 595), setpos(40, 40));
  btns[2] = set_btn(3, setpos(352, 595), setpos(40, 40));
  btns[3] = set_btn(4, setpos(467, 595), setpos(40, 40));
  btns[4] = set_btn(5, setpos(529, 595), setpos(40, 40));
  while (i++ < 5)
    (in_box_button(setpos(win->mouse.pos->x, win->mouse.pos->y), btns[i])) ?
    (block = btns[i].type) : 0;
  if (block > 0)
    {
      (block == 1) ? (paint->type = BKS_U) : 0;
      (block == 2) ? (paint->type = BKS_I) : 0;
      (block == 5) ? remove_layer(paint) : 0;
      (block == 4) ? add_layer(paint) : 0;
      (block == 3) ? paint->is_drug = 1 : 0;
    }
}

void		block_3(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[3];

  i = -1;
  block = 0;
  btns[0] = set_btn(BKS_W, setpos(848, 595), setpos(40, 40));
  btns[1] = set_btn(BKS_X, setpos(906, 595), setpos(40, 40));
  btns[2] = set_btn(BKS_C, setpos(963, 595), setpos(40, 40));
  while (i++ < 3)
    (in_box_button(setpos(win->mouse.pos->x, win->mouse.pos->y), btns[i])) ?
    (block = btns[i].type) : 0;
  if (block > 0)
    {
      (block == BKS_W) ? (paint->opt = 2) : 0;
      (block == BKS_X) ? (paint->opt = 1) : 0;
      (block == BKS_C) ? (paint->opt = 3) : 0;
    }
}

void		menu_block_plus(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[3];

  i = -1;
  btns[0] = set_btn(1, setpos(21, 595), setpos(200, 40));
  btns[1] = set_btn(2, setpos(240, 595), setpos(360, 40));
  btns[2] = set_btn(3, setpos(842, 595), setpos(182, 40));
  block = 0;
  while (i++ < 3)
    (in_box_button(setpos(win->mouse.pos->x, win->mouse.pos->y), btns[i])) ?
    (block = btns[i].type) : 0;
  if (block == 1)
    block_1(win, paint);
  if (block == 2)
    block_2(win, paint);
  if (block == 3)
    block_3(win, paint);
}

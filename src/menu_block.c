/*
** manu_block.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 28 11:19:05 2016 Walter Bonetti
** Last update Sun Jan 31 21:20:24 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

void		menu_block_save(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[3];

  i = 0;
  btns[0] = set_btn(1, setpos(25, 705), setpos(50, 50));
  btns[1] = set_btn(2, setpos(128, 717), setpos(30, 30));
  btns[2] = set_btn(3, setpos(173, 702), setpos(50, 50));
  while (i < 3)
    {
      if (in_box_button(setpos(win->mouse.pos->x,
      win->mouse.pos->y), btns[i]))
	block = btns[i].type;
      i++;
    }
  if (block == 1)
    export_format_bmp(win, paint);
  if (block == 2)
    color_swich(paint);
  if (block == 3)
    paint_save(paint);
}

void		menu_block_outils(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  t_button	btns[12];

  i = 0;
  btns[0] = set_btn(BKS_P, setpos(239, 650), setpos(50, 50));
  btns[1] = set_btn(BKS_K, setpos(296, 650), setpos(50, 50));
  btns[2] = set_btn(BKS_L, setpos(353, 650), setpos(50, 50));
  btns[3] = set_btn(BKS_A, setpos(410, 650), setpos(50, 50));
  btns[4] = set_btn(BKS_E, setpos(468, 650), setpos(50, 50));
  btns[5] = set_btn(BKS_T, setpos(526, 650), setpos(50, 50));
  btns[6] = set_btn(BKS_F, setpos(239, 705), setpos(50, 50));
  btns[7] = set_btn(BKS_G, setpos(296, 705), setpos(50, 50));
  btns[8] = set_btn(BKS_O, setpos(353, 705), setpos(50, 50));
  btns[9] = set_btn(BKS_Z, setpos(410, 705), setpos(50, 50));
  btns[10] = set_btn(BKS_R, setpos(468, 705), setpos(50, 50));
  btns[11] = set_btn(BKS_M, setpos(526, 705), setpos(50, 50));
  while (i < 12)
    {
      if (in_box_button(setpos(win->mouse.pos->x,
			       win->mouse.pos->y), btns[i]))
	(btns[i].type == BKS_M) ? (paint->menu_toggle = 0) :
	  (paint->type = btns[i].type);
      i++;
    }
}

void		menu_block_palette(t_fox_window *win, t_tekpain *paint)
{
  t_color	color;

  (void) win;
  (void) paint;
  if (win->mouse.state == GO_DOWN)
    {
      paint->current_color = fox_getpixelxy(paint->menu, win->mouse.pos->x,
					    win->mouse.pos->y - 581);
      color.full = paint->current_color;
      fox_draw_rectangle_fill(paint->menu, setpos(87, 123), setpos(30, 30),
			      color);
      color.full = paint->tmp_color[1];
      fox_draw_rectangle_fill(paint->menu, setpos(127, 139), setpos(30, 30),
			      color);
      paint->status = 1;
      paint->is_drug = 0;
    }
}

void	menu_block_settings_act(t_fox_window *win, t_tekpain *paint, int block)
{
  (void) win;
  (block == BKS_UP) ? paint_size_mode(win, paint, 1) : 0;
  (block == BKS_DOWN) ? paint_size_mode(win, paint, -1) : 0;
  (block == BKS_N) ? next_layer(paint) : 0;
  (block == BKS_B) ? back_layer(paint) : 0;
  (block == BKS_H) ? toggle_layer(paint) : 0;
  (block == BKS_LEFT) ? (paint->forme = 0) : 0;
  (block == BKS_RIGHT) ? (paint->forme = 1) : 0;
}

void	menu_block_settings(t_fox_window *win, t_tekpain *paint)
{
  int		i;
  int		block;
  t_button	btns[7];

  i = 0;
  btns[0] = set_btn(BKS_H, setpos(846, 650), setpos(50, 50));
  btns[1] = set_btn(BKS_DOWN, setpos(906, 650), setpos(50, 50));
  btns[2] = set_btn(BKS_UP, setpos(965, 650), setpos(50, 50));
  btns[3] = set_btn(BKS_B, setpos(846, 710), setpos(50, 25));
  btns[4] = set_btn(BKS_N, setpos(846, 735), setpos(50, 25));
  btns[5] = set_btn(BKS_LEFT, setpos(906, 710), setpos(50, 50));
  btns[6] = set_btn(BKS_RIGHT, setpos(965, 710), setpos(50, 50));
  block = -1;
  while (i < 7)
    {
      if (in_box_button(setpos(win->mouse.pos->x,
	win->mouse.pos->y), btns[i]))
	block = btns[i].type;
      i++;
    }
  if (block > 0)
    menu_block_settings_act(win, paint, block);
}

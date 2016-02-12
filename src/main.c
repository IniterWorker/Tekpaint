/*
** main.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Sat Jan  2 23:10:54 2016 Walter Bonetti
** Last update Sun Jan 31 23:27:43 2016 Michel Mancier
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/tekpaint.h"

void	key_ext(t_bunny_event_state	state,
		t_bunny_keysym		keysym,
		t_tekpain		*paint)
{
  if (state == GO_DOWN && keysym == BKS_UP && paint->size < 600)
    paint->size++;
  if (state == GO_DOWN && keysym == BKS_DOWN && paint->size > 1)
    paint->size--;
  if (state == GO_DOWN && keysym == BKS_LEFT)
    paint->forme = 0;
  if (state == GO_DOWN && keysym == BKS_RIGHT)
    paint->forme = 1;
  if (state == GO_DOWN && keysym == BKS_X)
    paint->opt = 1;
  if (state == GO_DOWN && keysym == BKS_W)
    paint->opt = 2;
  if (state == GO_DOWN && keysym == BKS_C)
    paint->opt = 3;
  if (state == GO_DOWN && keysym == BKS_PAGEUP && paint->trans_lvl < 255)
    paint->trans_lvl += 5;
  if (state == GO_DOWN && keysym == BKS_PAGEDOWN && paint->trans_lvl > 0)
    paint->trans_lvl -= 5;
}

t_bunny_response	callback_key(t_bunny_event_state 	state,
				     t_bunny_keysym 		keysym,
				     void 			*_data)
{
  t_fox_window		*window;
  t_tekpain		*paint;

  window = (t_fox_window *)_data;
  paint = window->_data;
  paint->line_begin = 1;
  (void) window;
  if (keysym == 36 && state)
    return (EXIT_ON_CROSS);
  if ((keysym == BKS_N || keysym == BKS_B) && state)
    (keysym == BKS_N) ? next_layer(window->_data) : back_layer(window->_data);
  if (keysym == 7 && state)
    toggle_layer(window->_data);
  if (keysym == BKS_TAB && state == GO_DOWN)
    color_swich(paint);
  key_ext(state, keysym, paint);
  if ((keysym == BKS_P || keysym == BKS_K || keysym == BKS_L ||
       keysym == BKS_A || keysym == BKS_E || keysym == BKS_T ||
       keysym == BKS_F || keysym == BKS_G || keysym == BKS_F4 ||
       keysym == BKS_F3 || keysym == BKS_O || keysym == BKS_R ||
       keysym == BKS_H || keysym == BKS_Z || keysym == BKS_U ||
       keysym == BKS_I || keysym == BKS_F1) && state)
    paint->type = keysym;
  toggle_menu(keysym, state, paint);
  return (GO_ON);
}

unsigned int	add_trans(unsigned int ucolor, unsigned char trans_lvl)
{
  t_color	color;

  color.full = ucolor;
  color.argb[3] = trans_lvl;
  return (color.full);
}

t_bunny_response	callback_loop(void *_data)
{
  t_fox_window		*window;
  t_tekpain		*paint;
  t_layer		*cur;

  window = (t_fox_window *)_data;
  paint = window->_data;
  drug(paint);
  paint->current_color = add_trans(paint->current_color, paint->trans_lvl);
  cur = paint->current_layer->data;
  (window->mouse.state == GO_UP) ? (paint->is_start = 1) : 0;
  one_click(&window->mouse, paint);
  menu_btn(window, paint);
  tools_action(paint, cur, window);
  if (!layers_dislpay_menu(paint) && paint->status && !(paint->status = 0))
    {
      set_background(window->buffer);
      blih_layers(window->buffer, &paint->layers);
      bunny_blit(&window->win->buffer, &window->buffer->clipable,
		 &window->zero_axis);
      if (paint->menu_toggle)
	bunny_blit(&window->win->buffer, &paint->menu->clipable,
		   &paint->menu_pos);
    }
  bunny_display(window->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_fox_window		*win;
  t_bunny_position	workzone;
  t_tekpain		*paint;

  workzone.x = 1024;
  workzone.y = 768;
  set_max_heap_size(30);
  win = FOX_DEF_DARK(1024, 768, "TekPaint - Brothers In Arms");
  splashscreen(win->win);
  fox_window_set_loop(win, callback_loop);
  fox_window_set_key(win, callback_key);
  fox_window_set_mouse(win, callback_click, callback_move);
  win->_data = (paint = tekpain_new(workzone));
  layer_init_list(win->_data);
  if (ac != 1)
    paint->path = av[1];
  else
    paint->path = NULL;
  paint->menu = bunny_load_pixelarray("resources/menu.png");
  update_create_format(win, paint);
  tekpaint_menu_draw_default(paint);
  fox_window_starter(win);
  tekpaint_close((t_tekpain *)win->_data);
  return (0);
}

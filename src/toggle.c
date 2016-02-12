/*
** toggle.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Jan 27 07:03:45 2016 Walter Bonetti
** Last update Sun Jan 31 23:27:14 2016 Michel Mancier
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/tekpaint.h"

void	toggle_menu(int	keysym, int state, t_tekpain *paint)
{
  if (!paint->status && keysym == 12 && state == 1)
    {
      paint->menu_toggle = !paint->menu_toggle;
      paint->status = 1;
    }
}

void	tools_action_p2(t_tekpain *paint, t_layer *cur, t_fox_window *window)
{
  int	i;
  void	(*pt_function[100])(t_window_mouse *, t_layer *, t_tekpain *);

  i = 0;
  while (i < 100 && (pt_function[i++] = NULL) == NULL);
  pt_function[BKS_A] = &paint_negatif;
  pt_function[BKS_E] = &paint_kinder;
  pt_function[BKS_T] = &paint_blur;
  pt_function[BKS_Z] = &paint_gris;
  pt_function[BKS_R] = &paint_salade;
  pt_function[BKS_P] = &paint_pincile_draw;
  pt_function[BKS_F] = &paint_bucket;
  pt_function[BKS_G] = &paint_gomme;
  pt_function[BKS_K] = &paint_pipette;
  pt_function[BKS_L] = &paint_line;
  pt_function[BKS_O] = &paint_spray;
  pt_function[BKS_U] = &paint_rect;
  pt_function[BKS_I] = &paint_elips;
  if (pt_function[paint->type] != NULL)
    (pt_function[paint->type])(&window->mouse, cur, paint);
  else
    (pt_function[BKS_P])(&window->mouse, cur, paint);
}

int	tools_action(t_tekpain *paint, t_layer *cur, t_fox_window *window)
{
  if (paint->menu_toggle && window->mouse.pos->y > 581)
    return (0);
  tools_action_p2(paint, cur, window);
  if (paint->status == 0 && paint->type == BKS_F4 && (paint->status = 1)
      && (paint->type = 1))
    paint_save(paint);
  if (paint->status == 0 && paint->type == BKS_F3 && (paint->status = 1)
      && (paint->type = 1))
    export_format_bmp(window, paint);
  if (paint->status == 0 && paint->type == BKS_F1 && (paint->status = 1)
      && (paint->type = 1))
    load_bmp_layer(paint);
  return (0);
}

void	update_create_format(t_fox_window *win, t_tekpain *paint)
{
  int	fd;

  fd = open(paint->path, O_RDONLY);
  import_format_fox(fd , win->_data);
  close(fd);
  if (paint->layers.count == 0)
    {
      layer_add(win->_data, layer_new("Default",
				bunny_new_pixelarray(paint->workzone.x,
						     paint->workzone.y),1));
    }
}

void	color_swich(t_tekpain *paint)
{
  unsigned int	tmp;
  t_color	color;

  tmp = paint->current_color;
  paint->current_color = paint->tmp_color[1];
  paint->tmp_color[0] = paint->tmp_color[1];
  paint->tmp_color[1] = tmp;
  color.full = paint->current_color;
  fox_draw_rectangle_fill(paint->menu, setpos(87, 123), setpos(30, 30),
                          color);
  color.full = paint->tmp_color[1];
  fox_draw_rectangle_fill(paint->menu, setpos(127, 139), setpos(30, 30),
                          color);
  paint->status = 1;
}

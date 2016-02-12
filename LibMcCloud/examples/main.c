/*
** main.c for Tests in /home/mei/Perso/LibMcCloud/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Tue Dec 22 15:32:53 2015 Michel Mancier
** Last update Fri Jan  8 15:59:35 2016 walter bonetti
*/

#include <stdlib.h>
#include <unistd.h>
#include "foxtek.h"
#include "./../include/foxwindow.h"
#include "my.h"

t_bunny_response	callback_move(const t_bunny_position	*relative,
				      void			*_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  my_printf(1, "[Mouse] pos .x: %d .y: %d\n", relative->x, relative->y);
  return (GO_ON);
}

t_bunny_response	callback_click(t_bunny_event_state	state,
				       t_bunny_mousebutton	button,
				       void			*_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  (void) button;
  (void) state;
  return (GO_ON);
}

t_bunny_response	callback_key(t_bunny_event_state 	state,
				     t_bunny_keysym 		keysym,
				     void 			*_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  if (keysym == 36 && state)
    return (0);
  my_printf(1, "key : %d\n", keysym);
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_fox_window		*window;

  window = _data;
  bunny_blit(&window->win->buffer,
	     &window->screen->clipable,
	     &window->zero_axis);
  bunny_display(window->win);
  return (GO_ON);
}

int		main()
{
  t_fox_window	*win;

  win = FOX_DEF_DARK(1024, 768, "mcloud");
  fox_window_set_loop(win, mainloop);
  fox_window_set_key(win, callback_key);
  fox_window_set_mouse(win, callback_click, callback_move);
  fox_window_starter(win);
  return (0);
}

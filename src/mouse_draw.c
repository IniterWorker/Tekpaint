/*
** mouse_draw.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 19 10:51:06 2016 Walter Bonetti
** Last update Sun Jan 31 19:03:07 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

t_bunny_response	callback_move(const t_bunny_position	*relative,
				      void			*_data)
{
  t_fox_window		*window;

  window = (t_fox_window *)_data;
  window->mouse.relative = relative;
  return (GO_ON);
}

t_bunny_response	callback_click(t_bunny_event_state	state,
				       t_bunny_mousebutton	button,
				       void			*_data)
{
  t_fox_window		*window;

  window = (t_fox_window *)_data;
  window->mouse.bouton = button;
  window->mouse.state = state;
  return (GO_ON);
}

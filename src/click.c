/*
** click.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sat Jan 30 23:56:34 2016 Walter Bonetti
** Last update Sun Jan 31 00:02:11 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

int	one_click(t_window_mouse *mouse, t_tekpain *paint)
{
  if (mouse->state == GO_UP)
    {
      paint->capture = 0;
    }
  if (mouse->state == GO_DOWN && !paint->capture && (paint->capture = 1))
    {
      paint->one_click = 1;
    }
  else
    {
      paint->one_click = 0;
    }
  return (0);
}

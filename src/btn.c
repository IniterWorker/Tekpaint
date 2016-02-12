/*
** btn.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 28 11:30:39 2016 Walter Bonetti
** Last update Thu Jan 28 11:30:54 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

t_button	set_btn(short				type,
			t_bunny_position		btn_pos,
			t_bunny_position		btn_size)
{
  t_button	btn;

  btn.type = type;
  btn.pos = btn_pos;
  btn.size = btn_size;
  return (btn);
}

t_bunny_position	setpos(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

int			in_box_button(t_bunny_position		ms_realative,
				      t_button			btn)
{
  if (ms_realative.x >= btn.pos.x && ms_realative.x <= (btn.size.x + btn.pos.x)
      && ms_realative.y >= btn.pos.y
      && ms_realative.y <= (btn.size.y + btn.pos.y))
    return (1);
  else
    return (0);
}

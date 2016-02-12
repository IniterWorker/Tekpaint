/*
** button.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Tue Jan 26 17:14:43 2016 Matthias RIGAUD
** Last update Sun Jan 31 23:38:40 2016 Michel Mancier
*/

#include <tekpaint.h>

t_btn	*create_button(char *path, t_bunny_position *pos, void *fonc)
{
  t_btn	*new;

  if ((new = bunny_malloc(sizeof(t_btn))) == NULL)
    return (NULL);
  if (!(new->pic = bunny_load_pixelarray(path)))
    return (NULL);
  new->pos.x = pos->x;
  new->pos.y = pos->y;
  new->fonc = fonc;
  return (new);
}

void	*check_button(t_btn **buttons,
		      const t_bunny_position *pos,
		      t_bunny_event_state state,
		      t_bunny_mousebutton key)
{
  int	i;

  i = -1;
  if (state != GO_DOWN || key != BMB_LEFT)
    return (NULL);
  while (buttons[i])
    {
      if (buttons[i]->pos.x <= pos->x &&
	  buttons[i]->pos.y <= pos->y &&
	  buttons[i]->pos.x + buttons[i]->pic->clipable.buffer.width
	  > pos->x &&
	  buttons[i]->pos.y + buttons[i]->pic->clipable.buffer.height
	  > pos->y)
	return (buttons[i]->fonc);
    }
  return (NULL);
}

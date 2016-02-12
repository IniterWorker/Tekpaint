/*
** list_history.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 26 09:35:32 2016 Walter Bonetti
** Last update Tue Jan 26 11:51:43 2016 Walter Bonetti
*/

#include "../include/tekpaint.h"

void	mouse_history_remove(t_node *node)
{
  bunny_free(node->data);
  bunny_free(node);
}

void	mouse_history_init(t_tekpain *paint)
{
  my_printf(1, "[mouse_history][list] initialisation\n");
  list_init(&paint->mouse_history, &mouse_history_remove);
}

t_bunny_position	*mouse_history_add(const t_bunny_position *mouse_pos)
{
  t_bunny_position	*pos;

  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (NULL);
  pos->x = mouse_pos->x;
  pos->y = mouse_pos->y;
  return (pos);
}

int	mouse_save(t_tekpain *paint, t_window_mouse *mouse)
{
  if (mouse->pos->x != ((t_bunny_position *)paint->mouse_history.last->data)->x
      && mouse->pos->y !=
      ((t_bunny_position *)paint->mouse_history.last->data)->y)
    list_add(&paint->mouse_history, node_new(mouse_history_add(mouse->pos)));
  return (0);
}

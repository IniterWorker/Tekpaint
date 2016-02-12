/*
** pix_list.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
** 
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
** 
** Started on  Tue Jan 26 00:07:08 2016 Matthias RIGAUD
** Last update Tue Jan 26 13:58:31 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

int	nw_pxlst(t_pxlst **old,
		 t_bunny_position *pos)
{
  t_pxlst	*new;

  if (!(new = bunny_malloc(sizeof(t_pxlst))) || !pos)
    return (1);
  new->pos.x = pos->x;
  new->pos.y = pos->y;
  new->next = *old;
  bunny_free(pos);
  *old = new;
  return (0);
}

t_pxlst		*dl_elem_pxlst(t_pxlst **old)
{
  t_pxlst	*new;

  if (!*old)
    return (NULL);
  new = (*old)->next;
  bunny_free(*old);
  return (new);
}

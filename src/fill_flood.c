/*
** fill_flood.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Mon Jan 25 23:01:17 2016 Matthias RIGAUD
** Last update Sun Jan 31 11:09:06 2016 Michel Mancier
*/

#include "../include/tekpaint.h"

void	stack_push(t_nodestack **top, int x, int y)
{
  t_nodestack	*new;

  if ((new = get_node(x, y)) != NULL)
    {
      new->next = (*top);
      *top = new;
    }
}

t_nodestack	*get_node(int x, int y)
{
  t_nodestack*	temp;

  temp = (t_nodestack*) bunny_malloc(sizeof(t_nodestack));
  if (temp == NULL)
    return (NULL);
  temp->pos.x = x;
  temp->pos.y = y;
  temp->next = NULL;
  return (temp);
}

int stack_empty(t_nodestack	*temp)
{
  if (temp == NULL)
    return 1;
  else
    return 0;
}

t_bunny_position	stack_pop(t_nodestack**top)
{
  t_bunny_position	item;
  t_nodestack		*temp;

  item = (*top)->pos;
  temp = *top;
  *top = (*top)->next;
  bunny_free(temp);
  return (item);
}

int			fill_flood(t_bunny_pixelarray 		*pix,
				   t_bunny_position 		*pos,
				   const t_color 		*color,
				   int 				*statu)
{
  t_nodestack		*stack;
  t_bunny_position	pop;
  unsigned int		ocolor;

  stack = NULL;
  if ((!(stack = NULL) && (pos->x < 0 || pos->y < 0 || pos->y >= H ||
	 pos->x >= W)) || ((ocolor = GXY(pix, pos->x, pos->y)) == color->full))
    return (1);
  stack_push(&stack, pos->x, pos->y);
  while (!stack_empty(stack) && ((pop = stack_pop(&stack)).x | 1 | 0))
    {
      fox_tekpixel(pix, &pop, color->full);
      if (pop.x + 1 < W && GXY(pix, pop.x + 1, pop.y) == ocolor)
	stack_push(&stack, pop.x + 1, pop.y);
      if (pop.x - 1 >= 0 && GXY(pix, pop.x - 1, pop.y) == ocolor)
	stack_push(&stack, pop.x - 1, pop.y);
      if (pop.y + 1 < H && GXY(pix, pop.x, pop.y + 1) == ocolor)
	stack_push(&stack, pop.x, pop.y + 1);
      if (pop.y - 1 >= 0 && GXY(pix, pop.x, pop.y - 1) == ocolor)
	stack_push(&stack, pop.x, pop.y - 1);
    }
  *statu = 1;
  return (0);
}

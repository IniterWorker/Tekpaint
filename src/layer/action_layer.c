/*
** action_layer.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 26 14:05:48 2016 Walter Bonetti
** Last update Sun Jan 31 21:18:19 2016 Walter Bonetti
*/

#include "../../include/tekpaint.h"

int	add_layer(t_tekpain *paint)
{
  char	line[1024];
  int	readed;

  my_printf(1, "[Layer] Add layer :name:");
  readed = read(0, line, 1024);
  line[readed - 1] = 0;
  if (*line != 0)
    {
      layer_add(paint, layer_new(line,
				      bunny_new_pixelarray(paint->workzone.x,
							paint->workzone.y),1));
      my_printf(1, "[Layer] Added with name : %s\n", line);
    }
  else
    my_printf(1, "[Layer] action stoped !\n");
  return (0);
}

int		remove_layer(t_tekpain *paint)
{
  t_layer	*cur;
  t_node	*tmp;

  cur = paint->current_layer->data;
  tmp = paint->current_layer;
  if (paint->layers.count == 1)
    return (my_printf(1, "[Layer] minimum one layer (ref: photoshop)\n"));
  next_layer(paint);
  my_printf(1, "[Layer] Remove current layer :name: %s\n", cur->name);
  list_remove_element(&paint->layers, tmp);
  paint->status = 1;
  return (0);
}

int		next_layer(t_tekpain *paint)
{
  t_layer	*cur;

  cur = paint->current_layer->data;
  if (paint->current_layer == paint->layers.last &&
      paint->current_layer == paint->layers.first)
    return (0);
  else if (paint->current_layer == paint->layers.last)
    paint->current_layer = paint->layers.first;
  else
    paint->current_layer = paint->current_layer->next;
  my_printf(1, "Current layer is : %s\n", cur->name);
  paint->status = 1;
  return (0);
}

int	back_layer(t_tekpain *paint)
{
  t_layer	*cur;

  cur = paint->current_layer->data;
  if (paint->current_layer == paint->layers.last &&
      paint->current_layer == paint->layers.first)
    return (0);
  else if (paint->current_layer == paint->layers.first)
    paint->current_layer = paint->layers.last;
  else
    paint->current_layer = paint->current_layer->prev;
  my_printf(1, "Current layer is : %s\n", cur->name);
  paint->status = 1;
  return (0);
}

int		toggle_layer(t_tekpain *paint)
{
  t_layer	*layer;

  if (paint->status == 0)
    {
      layer = paint->current_layer->data;
      if (!(layer->visible = !layer->visible))
	next_layer(paint);
      my_printf(1, "Toggle layer %s\n",
		((layer->visible) ? "visible" : "hidden"));
      paint->status = 1;
    }
  return (0);
}

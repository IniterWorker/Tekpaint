/*
** init_layer.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Jan 25 18:22:37 2016 Walter Bonetti
** Last update Fri Jan 29 11:06:00 2016 Walter Bonetti
*/

#include "../../include/tekpaint.h"

void		pf_remove(t_node *node)
{
  t_layer	*layer;

  layer = node->data;
  bunny_free(layer->name);
  bunny_delete_clipable(&layer->pix->clipable);
  bunny_free(node);
}

int	layer_init_list(t_tekpain *paint)
{
  my_printf(1, "[layer] initialisation\n");
  list_init(&paint->layers, &pf_remove);
  return (0);
}

int	layer_add(t_tekpain *paint, t_layer *layer)
{
  if ((list_add(&paint->layers, node_new(layer))) == 0)
    {
      my_printf(2, "[layer] erreur ");
      return (1);
    }
  else
    {
      paint->current_layer = paint->layers.last;
      my_printf(1, "[layer][list] added element\n");
      return (0);
    }
}

t_layer		*layer_new(char 			*name,
			   t_bunny_pixelarray 		*pix,
			   int				clean)
{
  t_layer	*new;
  t_color	alpha;

  if ((new = bunny_malloc(sizeof(t_layer))) == NULL)
    return (NULL);
  alpha.full = RGBA_C(0, 0, 0, 0);
  if (clean)
    fox_fill_array(pix , &alpha);
  if ((new->name = bunny_malloc(sizeof(char) * 1024)) == NULL)
    return (NULL);
  my_memset(new->name, 0, sizeof(char) * 1024);
  my_strcpy(new->name, name);
  new->pix = pix;
  new->visible = 1;
  new->is_modified = 1;
  return (new);
}

void		blih_layers(t_bunny_pixelarray *buffer, t_list *layers)
{
  t_node	*_node;
  t_layer	*cur;

  _node = layers->first;
  while (_node)
    {
      cur = _node->data;
      if (cur->visible == 1)
	paint_blit(buffer, cur->pix);
      _node = _node->next;
    }
}

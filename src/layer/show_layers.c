/*
** show_layers.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/layer/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Jan 31 20:44:49 2016 Walter Bonetti
** Last update Sun Jan 31 21:52:38 2016 Walter Bonetti
*/

#include "../../include/tekpaint.h"

int		layers_dislpay_menu(t_tekpain *paint)
{
  t_color	c;
  t_node	*_node;
  t_layer	*layer;
  int		iv[3];

  if (paint->status && (_node = paint->layers.first) != NULL
      && (iv[2] = paint->layers.count) && (c.full = WHITE) && !(iv[0] = 0))
    {
      fox_draw_rectangle_fill(paint->menu, setpos(581, 15), setpos(260, 50), c);
      iv[1] = (250 - (iv[2] * 10)) / iv[2];
      while (iv[0] < iv[2] && _node)
	{
	  layer = _node->data;
	  (layer->visible) ? (c.full = WBLUE) : (c.full = GREY);
          fox_draw_rectangle_fill(paint->menu,
	  setpos(591 + ((iv[1] + 10) * iv[0]) , 60), setpos(iv[1], 5), c);
	  c.full = (paint->current_layer == _node) ? RED : BLACK;
	  fox_draw_rectangle_fill(paint->menu,
				 setpos(591 + ((iv[1] + 10) * iv[0])
					, 20), setpos(iv[1], 40), c);
	  (_node = _node->next) ? iv[0]++ : iv[0]++;
	}
      paint->status = 1;
    }
  return (0);
}

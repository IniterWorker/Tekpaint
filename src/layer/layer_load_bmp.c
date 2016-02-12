/*
** layer_load_bmp.c for  in gfx_tekpaint/src/layer/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Jan 31 00:56:52 2016 Walter Bonetti
** Last update Sun Jan 31 22:24:47 2016 Michel Mancier
*/

#include <stdio.h>
#include "../../include/tekpaint.h"

t_bunny_pixelarray	*resize_bmp(t_bunny_pixelarray	*pix)
{
  t_bunny_pixelarray	*new;
  double		ratio;

  if (HB > HW || WB > WW)
    {
      ratio = (((double)HW / (double)HB < (double)WW / (double)WB)
	       ? ((double)HW / (double)HB)
	       : ((double)WW / (double)WB));
      new = bunny_new_pixelarray((int)((double)WB * ratio),
				 (int)((double)HB * ratio));
      fox_mod_stretch(new, pix);
      bunny_delete_clipable(&pix->clipable);
      pix = new;
    }
  return (pix);
}

void			error_invalid(void)
{
  my_printf(1, "Filename seems to be invalid.\n");
  my_printf(1, "Allowed extensions are '.bmp', '.png', '.gif' & '.jpg'.\n");
  my_printf(1, "If you want to cancel, return directly.\n");
}

int			load_bmp_layer(t_tekpain *paint)
{
  char			line[1024];
  t_bunny_pixelarray	*pix;
  int			readed;

  my_printf(1, "[IMPORT] Load an image:\nPath: ");
  readed = read(0, line, 1024);
  line[readed - 1] = 0;
  if (line[0] == 0)
    return (0);
  else if ((match(line, "*.bmp") == 1) || (match(line, "*.png") == 1)
	   || (match(line, "*.gif") == 1) || (match(line, "*.jpg") == 1))
    {
      if ((pix = bunny_load_pixelarray(line)) == NULL)
	return (my_printf(1, "Error while loading the file.. Cancelling.\n"));
      pix = resize_bmp(pix);
      layer_add(paint, layer_new(line, pix, 0));
      paint->status = 1;
      my_printf(1, "Layer added with following name: %s\n", line);
    }
  else
    {
      error_invalid();
      load_bmp_layer(paint);
    }
  return (0);
}

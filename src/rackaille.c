/*
** rackaille.c for rackaille in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Wed Jan 27 02:48:45 2016 Matthias RIGAUD
** Last update Wed Jan 27 03:47:15 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

void			rackaille(t_bunny_pixelarray		*pix,
				  const t_bunny_position	*pos,
				  t_color			*color,
				  int				size)
{
  t_bunny_position      npos;
  double                i;

  size++;
  while (--size)
    {
      i = 0;
      while (i < 360)
	{
	  npos.x = pos->x + size * cos(i * 2 * M_PI / 360);
	  npos.y = pos->y + size * sin(i * 2 * M_PI / 360);
	  if (!(rand() % (5000 / size)))
	    fox_tekpixel(pix, &npos, color->full);
	  i += 0.1;
	}
    }
}

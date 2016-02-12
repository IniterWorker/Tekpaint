/*
** splashscreen.c for Splashscreen in /home/mei/Rendu/gfx_tekpaint/src
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Sun Jan 31 09:38:58 2016 Michel Mancier
** Last update Sun Jan 31 23:42:10 2016 Michel Mancier
*/

#include "tekpaint.h"

t_bunny_response	splash_key(t_bunny_event_state	state,
				   t_bunny_keysym	keysym,
				   void			*data)
{
  t_bunny_effect	*lol;
  lol = data;
  if (keysym == BKS_SPACE && state == GO_DOWN)
    {
      bunny_sound_stop(lol);
      return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response	splash_loop(void	*data)
{
  (void)data;
  return (GO_ON);
}

void			splashscreen(t_bunny_window	*win)
{
  t_bunny_pixelarray	*splash;
  t_bunny_effect	*lol;

  splash = bunny_load_pixelarray("resources/splashscreen.png");
  fox_blit_upleft(win, splash);
  lol = bunny_load_effect("resources/splash.ogg");
  bunny_sound_volume(lol, 100);
  bunny_sound_play(lol);
  bunny_sound_loop(lol, false);
  bunny_set_loop_main_function(&splash_loop);
  bunny_set_key_response(&splash_key);
  bunny_display(win);
  bunny_loop(win, 60, lol);
  bunny_delete_clipable(&splash->clipable);
}

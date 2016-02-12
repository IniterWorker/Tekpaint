/*
** foxwindow.h for  in /home/bonett_w/Documents/perso/LibMcCloud/include/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Dec 29 23:13:48 2015 walter bonetti
** Last update Wed Jan 27 05:36:43 2016 Matthias RIGAUD
*/

#ifndef FOXWINDOW_H_
# define FOXWINDOW_H_

# include <lapin.h>

/*
** Fox Window Framework
** Your time is running out !
*/

typedef struct			s_window_mouse
{
  const t_bunny_position	*pos;
  t_bunny_position		prev;
  const t_bunny_position	*relative;
  t_bunny_event_state		state;
  t_bunny_mousebutton		bouton;
}				t_window_mouse;

typedef struct			s_fox_window
{
  t_bunny_window		*win;
  t_bunny_pixelarray		*screen;
  t_bunny_pixelarray		*buffer;
  t_bunny_position		zero_axis;
  t_bunny_loop			loop;
  t_bunny_key			key;
  t_bunny_click			click;
  t_bunny_move			move;
  t_window_mouse		mouse;
  char				lisen_key;
  char				lisen_mouse;
  void				*_data;
}				t_fox_window;

/*
** Window Allocation
*/

t_fox_window	*fox_window_new(unsigned int 		width,
				unsigned int 		height,
				t_bunny_window_style 	winstyle,
				const char 		*window_name);

void	fox_window_delete(t_fox_window *window);

/*
** Window Init
*/

void	fox_window_set_loop(t_fox_window *window, t_bunny_loop loop);
void	fox_window_set_key(t_fox_window *window, t_bunny_key key);
void	fox_window_set_mouse(t_fox_window 		*window,
				     t_bunny_click 	click,
				     t_bunny_move 	move);
void	fox_window_init_screen(t_fox_window *window, unsigned int color);
void	fox_window_color(t_fox_window *window, unsigned int color);
void	fox_window_set_screen(t_fox_window 		*window,
			      t_bunny_pixelarray 	*pix);
t_fox_window	*fox_window_default_darkfox(unsigned int w,
					    unsigned int h,
					    t_bunny_window_style winstyle,
					    char *name);
void	fox_window_starter(t_fox_window *window);

/*
** MACRO
** Because Time is Money
*/

# define FOX_TYPE TITLEBAR | CLOSE_BUTTON
# define FOX_DEFAULT_WINDOW(w, h, n) (fox_window_new(w, h, FOX_TYPE, (n)))
# define FOX_DEF_DARK(w, h, n) (fox_window_default_darkfox(w, h, FOX_TYPE, (n)))
# define FOX_DEFAULT_BACKGROUND(w, color) (fox_window_color(w, color))
# define FOX_DEFAULT
#endif /* !FOXWINDOW_H_ */

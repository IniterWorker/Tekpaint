/*
** list.h for  in /home/bonett_w/Documents/rendu/list/include/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 21 20:22:48 2016 Walter Bonetti
** Last update Sun Jan 31 09:02:48 2016 Michel Mancier
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>

typedef struct	s_node
{
  void		*data;
  struct s_node	*next;
  struct s_node *prev;
}		t_node;

typedef struct	s_list
{
  struct s_node	*first;
  struct s_node	*last;
  unsigned int	count;
  void		(*pf_rm)(struct s_node *node);
}		t_list;

/*
** List functions
** NEED to set rm function
*/

int	list_init(t_list *list, void (*pf_rm)(struct s_node *node));
int	list_add(t_list *list, t_node *node);
int	list_is_empty(t_list *list);
int	list_remove_element(t_list *list, t_node *node);
void	list_destructeur(t_list *list);

/*
** Node functions
*/

t_node	*node_new(void *data);

#endif /* !LIST_H_ */

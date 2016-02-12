/*
** remove.c for  in /home/bonett_w/Documents/rendu/PSU_2015_minishell1/list/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 21 16:44:50 2016 Walter Bonetti
** Last update Thu Jan 21 20:23:33 2016 Walter Bonetti
*/

#include "include/list.h"

static void	list_remove_at_top(t_list *list, t_node *node)
{
  list->first = node->next;
  list->first->prev = NULL;
}

static void	list_remove_at_end(t_list *list, t_node *node)
{
  list->last = node->prev;
  list->last->next = NULL;
}

static void	list_remove_at_center(t_list *list, t_node *node)
{
  t_node	*before;
  t_node	*after;

  (void) list;
  before = node->prev;
  after = node->next;
  before->next = after;
  after->prev = before;
}

int	list_remove_element(t_list *list, t_node *node)
{
  if (!list_is_empty(list) && node)
    {
      if (list->first == node && list->last == node)
	{
	  list->first = NULL;
	  list->last = NULL;
	}
      else if (list->first == node)
	list_remove_at_top(list, node);
      else if (list->last == node)
	list_remove_at_end(list, node);
      else
	list_remove_at_center(list, node);
      list->count--;
      (list->pf_rm)(node);
      return (list->count);
    }
  return (0);
}

void	list_destructeur(t_list *list)
{
  while (list_remove_element(list, list->first));
}

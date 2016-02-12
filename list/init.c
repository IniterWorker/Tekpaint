/*
** init.c for  in /home/bonett_w/Documents/rendu/PSU_2015_minishell1/list/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 21 16:38:23 2016 Walter Bonetti
** Last update Sat Jan 23 18:13:12 2016 Walter Bonetti
*/

#include "include/list.h"

int	list_init(t_list *list, void (*pf_rm)(struct s_node *node))
{
  list->first = NULL;
  list->last = NULL;
  list->count = 0;
  list->pf_rm = pf_rm;
  return (0);
}

int	list_add(t_list *list, t_node *node)
{
  if (list->first == NULL)
    {
      list->first = node;
      list->last = node;
    }
  else
    {
      list->last->next = node;
      node->prev = list->last;
      list->last = node;
    }
  list->count++;
  return (list->count);
}

int	list_is_empty(t_list *list)
{
  return (list->count == 0);
}

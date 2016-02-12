/*
** node.c for  in /home/bonett_w/Documents/rendu/PSU_2015_minishell1/list/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Jan 21 17:00:11 2016 Walter Bonetti
** Last update Thu Jan 21 20:23:27 2016 Walter Bonetti
*/

#include <lapin.h>
#include "include/list.h"

t_node	*node_new(void *data)
{
  t_node	*node;

  if ((node = bunny_malloc(sizeof(*node))) == NULL)
    return (NULL);
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

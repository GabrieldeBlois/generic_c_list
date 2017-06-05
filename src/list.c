/*
** list.c for list in /home/gaby/Documents/dev/generic_c_list/src
**
** Made by gaby
** Login   <gabriel.de-blois@epitech.eu>
**
** Started on  Tue May 30 16:56:10 2017 gaby
** Last update Wed May 31 18:11:55 2017 Matthis Le Texier
*/

#include <stdio.h>
#include "../include/list.h"

__inline__ t_list*
list_new_node(void* data, t_list* next, t_list* prev)
{
  t_list* tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp->next = next;
  tmp->prev = prev;
  tmp->data = data;
  return (tmp);
}

__inline__ size_t
list_len(t_list* list)
{
  int i;

  i = 0;
  while (list) {
    list = list->next;
    ++i;
  };
  return (i);
}

t_list*
list_at(t_list* list, size_t pos)
{
  size_t i;

  i = 0;
  while (list && i < pos) {
    ++i;
    list = list->next;
  }
  return (list);
}

t_list*
list_find(t_list* list, void *looked_for, t_comparison_func pred)
{
  while (list) {
    if (pred(list->data, looked_for))
      return (list);
    list = list->next;
  }
  return (NULL);
}



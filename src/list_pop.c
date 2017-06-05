#include "list.h"

t_list*
list_pop_front(t_list* list, t_free_func func)
{
  t_list* tmp;

  tmp = list->next;
  list_freenode(list, func);
  if (tmp)
    tmp->prev = NULL;
  return (tmp);
}

t_list*
list_pop_back(t_list* list, t_free_func func)
{
  t_list* tmp;

  tmp = list;
  if (!list)
    return (NULL);
  while (tmp->next)
    tmp = tmp->next;
  if (!tmp->prev)
    return (list_freenode(tmp, func), NULL);
  tmp = tmp->prev;
  list_freenode(tmp->next, func);
  tmp->next = NULL;
  return (tmp);
}
#include "list.h"

__inline__ t_list*
list_push_front(t_list* list, t_list* node)
{
  if (!node)
    return (list);
  node->prev = NULL;
  node->next = list;
  if (list)
    list->prev = node;
  return (node);
}

t_list*
list_push_back(t_list* list, t_list* node)
{
  t_list* tmp;

  tmp = list;
  if (!list)
    return (node->prev = NULL, node->next = NULL, node);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = node;
  return (node->prev = tmp, node->next = NULL, list);
}
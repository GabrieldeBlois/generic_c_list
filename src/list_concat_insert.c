#include "list.h"

t_list*
list_insert(t_list* list, t_list* node, size_t pos)
{
  size_t i;
  t_list* tmp;

  if (!list)
    return (list_push_front(NULL, node));
  i = 0;
  tmp = list;
  while (tmp->next && i < pos) {
    tmp = tmp->next;
    ++i;
  }
  node->prev = tmp;
  node->next = tmp->next;
  tmp->next = node;
  node->next->prev = node;
  return (list);
}

t_list*
list_concat(t_list* l1, t_list* l2)
{
  t_list* ret;

  if (!l1)
    return (l2);
  ret = l1;
  while (l1->next)
    l1 = l1->next;
  l1->next = l2;
  l2->prev = l1;
  return (ret);
}
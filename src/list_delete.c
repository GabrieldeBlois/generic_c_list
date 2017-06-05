#include "list.h"

t_list*
list_delete_node(t_list* list, t_list* node, t_free_func func)
{
  if (!node->prev) {
    list = list->next;
    if (list)
      list->prev = NULL;
    list_freenode(node, func);
    return (list);
  }
  node->prev->next = node->next;
  if (node->next)
    node->next->prev = node->prev;
  list_freenode(node, func);
  return (list);
}

t_list*
list_delete_from_data(t_list* list, void* todelete, t_free_func func)
{
  t_list* tmp;

  tmp = list;
  while (tmp) {
    if (tmp->data == todelete) {
      return (list_delete_node(list, tmp, func));
    }
    tmp = tmp->next;
  }
  return (list);
}
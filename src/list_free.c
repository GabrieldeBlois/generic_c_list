#include "list.h"

void
list_free(t_list* list, t_free_func func)
{
  t_list* tmp;

  if (!list)
    return;
  tmp = list->next;
  while (tmp) {
    list_freenode(list, func);
    list = tmp;
    tmp = tmp->next;
  }
  list_freenode(list, func);
}

__inline__ void
list_freenode(t_list* ptr, t_free_func func)
{
  func(ptr->data);
  free(ptr);
}
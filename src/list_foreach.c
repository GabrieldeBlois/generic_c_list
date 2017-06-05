#include "list.h"

void
list_foreach(t_list* list, t_foreach_func func)
{
  while (list) {
    func(list->data);
    list = list->next;
  }
}

void
list_foreach_until(t_list* list, t_foreach_until_func func)
{
  while (list) {
    int i = 0;
    printf("avant de seg %p\n", list);
    if ((i = func(list->data)) == 0)
    {
        printf("coucou\n");
      return ;
    }
        printf("avant de seg i = %d\n", i);
    if (list)
      list = list->next;
  }
}

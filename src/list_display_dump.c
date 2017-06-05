#include <stdio.h>
#include "list.h"

void
list_display(t_list* list, t_display_func func)
{
  while (list) {
    func(list->data);
    list = list->next;
  }
}

void
list_dump_addresses(t_list* list, char* customdebug)
{
  int i;

  if (customdebug) {
    printf("\n%s - - - - - - - - - - - - -\n", customdebug);
  }
  i = 0;
  while (list) {
    printf("node %4d: %p <- %p -> %p\n", i++, list->prev, list, list->next);
    list = list->next;
  }
}

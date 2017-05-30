#ifndef LIST_SORT_H_
#define LIST_SORT_H_

#include "list.h"

typedef struct s_list_sort
{
    struct s_list_sort *left;
    struct s_list_sort *right;
    t_list *node;
}   t_list_sort;

#endif /* guards */
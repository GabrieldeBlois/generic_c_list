#ifndef LIST_CTRL_H_
#define LIST_CTRL_H_

#include "list.h"

typedef struct s_list_ctrl
{
    t_list *head;
    t_list *tail;
}   t_list_ctrl;

void list_ctrl_push_front(t_list_ctrl *list, t_list *node);

void list_ctrl_push_back(t_list_ctrl *list, t_list *node);

void list_ctrl_pop_front(t_list_ctrl *list, t_free_func func);

void list_ctrl_pop_back(t_list_ctrl *list, t_free_func func);

size_t list_ctrl_len(t_list_ctrl *list);

void list_ctrl_free(t_list_ctrl *controler, t_free_func func);

#endif
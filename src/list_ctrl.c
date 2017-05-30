#include "list_ctrl.h"

__inline__
void list_ctrl_push_front(t_list_ctrl *list, t_list *node) {
    list->head = list_push_front(list->head, node);
}

__inline__
void list_ctrl_push_back(t_list_ctrl *list, t_list *node) {
    if (!list->head)
    {
        node->prev = NULL;
        node->next = NULL;
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        node->next = NULL;
    }
}

__inline__
void list_ctrl_pop_front(t_list_ctrl *list, t_free_func func) {
    t_list *tmp;

    if (!list->head)
        return ;
    tmp = list->head->next;
    list_freenode(list->head, func);
    if (tmp)
        tmp->prev = NULL;
    else
        list->tail = NULL;
    list->head = tmp;
}

__inline__
void list_ctrl_pop_back(t_list_ctrl *list, t_free_func func) {
    t_list *tmp;

    if (!list->tail)
        return ;
    if (!(tmp = list->tail->prev))
    {
        list_freenode(list->tail, func);
        list->head = NULL;
        list->tail = NULL;
        return ;
    }
    list_freenode(list->tail, func);
    tmp->next = NULL;
    list->tail = tmp;
}

__inline__
size_t list_ctrl_len(t_list_ctrl *list) {
    int i;
    t_list *tmp;

    tmp = list->head;
    i = 0;
    while (tmp) {
        tmp = tmp->next;
        ++i;
    };
    return (i);
}

void list_ctrl_free(t_list_ctrl *controler, t_free_func func)
{
    list_free(controler->head, func);
    free(controler);
}
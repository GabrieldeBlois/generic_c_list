#ifndef LIST_H_
#define LIST_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prev;
    void *data;
}   t_list;

typedef int bool;
typedef bool (*t_predicate_func)(void *);
typedef void (*t_display_func)(void *);
typedef void (*t_free_func)(void *);
typedef int (*t_comparison_func)(void *d1, void *d2);

t_list *list_new_node(void *data, t_list *next, t_list *prev);

t_list *list_push_front(t_list *list, t_list *node);

t_list *list_push_back(t_list *list, t_list *node);

size_t list_len(t_list *list);

t_list *list_insert(t_list *list, t_list *node, size_t pos);

t_list *list_at(t_list *, size_t pos);

t_list *list_find(t_list *list, t_predicate_func pred);
void list_display(t_list *list, t_display_func func);

t_list *list_pop_front(t_list *list, t_free_func func);

t_list *list_pop_back(t_list *list, t_free_func func);

void list_freenode(t_list *ptr, t_free_func func);

void list_free(t_list *list, t_free_func func);

t_list *list_sort(t_list *list, t_comparison_func func);
t_list *list_concat(t_list *l1, t_list *l2);

#endif /* guards */

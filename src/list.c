/*
** list.c for list in /home/gaby/Documents/dev/generic_c_list/src
**
** Made by gaby
** Login   <gabriel.de-blois@epitech.eu>
**
** Started on  Tue May 30 16:56:10 2017 gaby
** Last update Tue May 30 16:56:12 2017 gaby
*/

#include "list.h"

__inline__
t_list *list_new_node(void *data,
		      t_list *next,
		      t_list *prev)
{
  t_list *tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp->next = next;
  tmp->prev = prev;
  tmp->data = data;
  return (tmp);
}

__inline__
t_list *list_push_front(t_list *list, t_list *node)
{
  if (!node)
    return (list);
  node->prev = NULL;
  node->next = list;
  return (node);
}

__inline__
t_list *list_push_back(t_list *list, t_list *node)
{
  t_list *tmp;

  tmp = list;
  if (!list)
    return (node->prev = NULL, node->next = NULL, node);
  while (tmp->next) tmp = tmp->next;
  tmp->next = node;
  return (node->prev = tmp, node->next = NULL, list);
}

__inline__
t_list *list_pop_front(t_list *list, t_free_func func)
{
  t_list *tmp;

  tmp = list->next;
  list_freenode(list, func);
  if (tmp)
    tmp->prev = NULL;
  return (tmp);
}

__inline__
t_list *list_pop_back(t_list *list, t_free_func func)
{
  t_list *tmp;

  tmp = list;
  if (!list)
    return (NULL);
  while (tmp->next) tmp = tmp->next;
  if (!tmp->prev)
    return (list_freenode(tmp, func), NULL);
  tmp = tmp->prev;
  list_freenode(tmp->next, func);
  tmp->next = NULL;
  return (tmp);
}

__inline__
void list_freenode(t_list *ptr, t_free_func func)
{
  func(ptr->data);
  free(ptr);
}

__inline__
size_t list_len(t_list *list)
{
  int i;

  i = 0;
  while (list) {
    list = list->next;
    ++i;
  };
  return (i);
}

void list_free(t_list *list, t_free_func func)
{
    t_list *tmp;

    if (!list)
      return ;
    tmp = list->next;
    while (tmp)
      {
        list_freenode(list, func);
        list = tmp;
        tmp = tmp->next;
      }
    list_freenode(list, func);
}

t_list *list_insert(t_list *list, t_list *node, size_t pos)
{
  size_t i;
  t_list *tmp;

  if (!list)
    return (list_push_front(NULL, node));
  i = 0;
  tmp = list;
  while (tmp->next && i < pos)
    {
      tmp = tmp->next;
      ++i;
    }
  node->prev = tmp;
  node->next = tmp->next;
  tmp->next = node;
  node->next->prev = node;
  return (list);
}

t_list *list_at(t_list *list, size_t pos)
{
  size_t i;

  i = 0;
  while (list && i < pos) {
    ++i;
    list = list->next;
  }
  return (list);
}

t_list *list_find(t_list *list, t_predicate_func pred)
{
  while (list && !pred(list->data)) {
    list = list->next;
  }
  return (list);
}

void list_display(t_list *list, t_display_func func)
{
  while (list) {
    func(list->data);
    list = list->next;
  }
}

t_list *list_concat(t_list *l1, t_list *l2)
{
  t_list *ret;

  if (!l1)
    return (l2);
  ret = l1;
  while (l1->next)
    l1 = l1->next;
  l1->next = l2;
  l2->prev = l1;
  return (ret);
}

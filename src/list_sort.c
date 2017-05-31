/*
** list_sort.c for t in /home/gaby/Documents/dev/generic_c_list
**
** Made by gaby
** Login   <gabriel.de-blois@epitech.eu>
**
** Started on  Tue May 30 17:27:17 2017 gaby
** Last update Tue May 30 17:27:19 2017 gaby
*/

#include "list_sort.h"
#include <stdio.h>

__inline__ static t_list_sort*
new_tree_node(t_list* node)
{
  t_list_sort* tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->node = node;
  return (tmp);
}

__inline__ static void
add_to_tree(t_list_sort** root, t_list* node, t_comparison_func func)
{
  while (*root)
    root = (func((*root)->node->data, node->data) <= 0) ? &(*root)->left
                                                        : &(*root)->right;
  *root = new_tree_node(node);
}

static t_list*
destack_tree(t_list_sort* root)
{
  t_list* list;

  list = NULL;
  if (!root)
    return (NULL);
  if (root->left)
    list = destack_tree(root->left);
  list = (list_push_front(list, root->node));
  if (root->right)
    list = list_concat(destack_tree(root->right), list);
  free(root);
  return (list);
}

void
print_tree(t_list_sort* root)
{
  if (!root)
    return;
  if (root->left)
    print_tree(root->left);
  int a = *(int*)(root->node->data);
  printf("debug - %d\n", a);
  if (root->right)
    print_tree(root->right);
  free(root);
}

t_list*
list_sort(t_list* list, t_comparison_func func)
{
  t_list_sort* root;

  root = NULL;
  while (list) {
    add_to_tree(&root, list, func);
    list = list->next;
  }
  list = destack_tree(root);
  return (list);
}

#include "list_sort.h"
#include <stdio.h>

__inline__ static t_list_sort* new_tree_node(t_list* node) {
  t_list_sort* tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (NULL);
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->node = node;
  return (tmp);
}

static t_list_sort* add_to_tree_recur(t_list_sort* root,
                                      t_list* node,
                                      t_comparison_func func) {
  if (!root)
    return new_tree_node(node);
  else if (func(root->node->data, node->data) <= 0)
    root->left = add_to_tree_recur(root->left, node, func);
  else
    root->right = add_to_tree_recur(root->right, node, func);
  return (root);
}

__inline__ static void add_to_tree(t_list_sort** root,
                                   t_list* node,
                                   t_comparison_func func) {
  while (*root)
    root = (func((*root)->node->data, node->data) <= 0) ? &(*root)->left
                                                        : &(*root)->right;
  *root = new_tree_node(node);
}

static t_list* destack_tree(t_list_sort* root) {
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

void print_tree(t_list_sort* root) {
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

t_list* list_sort(t_list* list, t_comparison_func func) {
  t_list_sort* root;

  root = NULL;
  while (list) {
    add_to_tree(&root, list, func);
    list = list->next;
  }
  list = destack_tree(root);
  return (list);
}
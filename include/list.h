/*
** list.h for list in /home/gaby/Documents/dev/generic_c_list/src
**
** Made by gaby
** Login   <gabriel.de-blois@epitech.eu>
**
** Started on  Tue May 30 16:56:38 2017 gaby
** Last update Tue May 30 16:59:42 2017 gaby
*/

#ifndef LIST_H_
# define LIST_H_

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
  struct	s_list *next;
  struct	s_list *prev;
  void *data;
}		t_list;

typedef int	bool;
typedef bool	(*t_predicate_func)(void *);
typedef void	(*t_display_func)(void *);
typedef void	(*t_free_func)(void *);
typedef int (*t_comparison_func)(void* d1, void* d2);
typedef void (*t_foreach_func)(void *);
typedef int (*t_foreach_until_func)(void *);

t_list *list_delete_node(t_list *list, t_list *node, t_free_func);
t_list *list_delete_from_data(t_list *list, void *todelete, t_free_func func);


/*
**	creates a new node of type t_list from a data as void*
**	you can specify a next and a prev but it will be most of the time NULL NULL;
*/

t_list		*list_new_node(void *data,
			       t_list *next,
			       t_list *prev);

/*
**	adds the given node to the beginning of the list
**	dont forget that you must get the new list pointer as list is passed by copy
*/

t_list		*list_push_front(t_list *list,
				 t_list *node);

/*
**	adds the given node to the end of the list
**	dont forget that you must get the new list pointer as list is passed by copy
*/

t_list		*list_push_back(t_list *list,
				t_list *node);

/*
** 	returns the list length
*/

size_t		list_len(t_list *list);

/*
**	inserts the given node at the given pos.
** 	if the pos is not reachable, it puts the node at the end of the list
** 	in the case of a NULL list, it returns the given node as a new list
*/

t_list		*list_insert(t_list *list,
			     t_list *node,
			     size_t pos);

/*
**	gets the node at the given position. NULL otherwise.
*/

t_list		*list_at(t_list *,
			 size_t pos);

/*
**	find the first occurance of to_compare thanks to the comparison function pointer
** 	you must code yourself the function pointed for it to suits your desires.
*/

t_list		*list_find(t_list *list,
						void *to_compare,
			   			t_comparison_func func);

/*
**	it's exactly like the foreach function; named differently to be more understandable
*/

void		list_display(t_list *list,
			     t_display_func func);

/*
**	deletes the first node of a t_list and returns its new pointer.
**	be caution it's not like list.pop in cpp, it does not return the pointer of the deleted node;
** 	the t_free_func is for you to free your datas if needed
*/

t_list		*list_pop_front(t_list *list,
				t_free_func func);

t_list		*list_pop_back(t_list *list,
			       t_free_func func);

/*
**	frees a single t_list node
*/

void		list_freenode(t_list *ptr,
			      t_free_func func);

/*
**	frees an entire t_list
*/

void		list_free(t_list *list,
			  t_free_func func);

/*
**	sorts the list thanks to the given predicate.
** 	returns a pointer to the new sorted list / NULL if there was a problem (malloc fail for instance)
*/

t_list		*list_sort(t_list *list,
			   t_comparison_func func);

/*
** 	concats the second list at the end of the first one.
** 	returns a pointer to the new concatained list
*/

t_list		*list_concat(t_list *l1,
			     t_list *l2);

/*
** 	executes a function for each node of the list
*/

void 		list_foreach(t_list *, t_foreach_func func);

/*
**	foreach_until does the same thing as foreach until the function pointer executed returns 0 (false);
*/

void 		list_foreach_until(t_list *, t_foreach_until_func func);

void list_dump_addresses(t_list *list, char *customdebug);

#endif /* guards */

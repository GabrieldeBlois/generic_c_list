/*
** list_sort.h for list in /home/gaby/Documents/dev/generic_c_list/src
** 
** Made by gaby
** Login   <gabriel.de-blois@epitech.eu>
** 
** Started on  Tue May 30 17:00:05 2017 gaby
** Last update Tue May 30 17:02:08 2017 gaby
*/

#ifndef		LIST_SORT_H_
# define	LIST_SORT_H_

# include	"list.h"

typedef struct	s_list_sort
{
    struct	s_list_sort *left;
    struct	s_list_sort *right;
		t_list *node;
}		t_list_sort;

#endif /* guards */

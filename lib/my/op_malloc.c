/*
** my_malloc.c for powerful_malloc in /home/victor/Tests/malloc_free_all
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Mar 22 15:51:33 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:35:56 2017 Victor LE DANTEC
*/

#include "libmy.h"

t_malloc		*get_array()
{
  static t_malloc	*array;

  if (!array)
    {
      array = my_malloc(sizeof(t_malloc));
      array->ptrs = NULL;
      array->size = 0;
    }
  return (array);
}

void	dup_array(t_malloc *array, long unsigned int *newarray)
{
  int	i;

  i = 0;
  while (i < array->size - 1)
    {
      newarray[i] = array->ptrs[i];
      i++;
    }
}

void			add_entry_to_array(t_malloc *array, void *ptr)
{
  long unsigned int	*newarray;

  array->size++;
  newarray = my_malloc(sizeof(long unsigned int) * array->size);
  if (array->size != 1)
    dup_array(array, newarray);
  newarray[array->size - 1] = (long unsigned int)ptr;
  my_free(array->ptrs);
  array->ptrs = newarray;
}

void		*op_malloc(size_t size)
{
  void		*ptr;
  t_malloc	*array;

  array = get_array();
  ptr = my_malloc(size);
  add_entry_to_array(array, ptr);
  return (ptr);
}

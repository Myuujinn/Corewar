/*
** op_free.c for op_free in /home/victor/Tests/malloc_free_all
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Mar 22 17:10:58 2017 Victor LE DANTEC
** Last update Wed Mar 22 17:35:08 2017 Victor LE DANTEC
*/

#include "libmy.h"

void	my_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}

void	op_free()
{
  t_malloc	*array;
  int		i;

  array = get_array();
  i = 0;
  while (i < array->size)
    my_free((void *)array->ptrs[i++]);
  my_free(array->ptrs);
  my_free(array);
}

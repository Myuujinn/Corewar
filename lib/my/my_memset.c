/*
** my_memset.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:43:34 2017 Victor LE DANTEC
** Last update Fri Jan  6 21:50:55 2017 Victor LE DANTEC
*/

#include <stdlib.h>

void		*my_memset(void *s, int c, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    ((char *)s)[i++] = c;
  return (s);
}

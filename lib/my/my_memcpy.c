/*
** my_memcpy.c for libmy-reboot in /home/victor/Libmy
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Mar 22 17:38:54 2017 Victor LE DANTEC
** Last update Wed Mar 22 17:45:24 2017 Victor LE DANTEC
*/

#include <stddef.h>

void		my_memcpy(void *dest, void *src, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    {
      ((char *)dest)[i] = ((char *)src)[i];
      i++;
    }
}

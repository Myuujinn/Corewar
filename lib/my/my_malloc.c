/*
** my_malloc.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 19:34:58 2017 Victor LE DANTEC
** Last update Wed Mar  8 17:06:45 2017 Victor LE DANTEC
*/

#include <stdlib.h>

void	*my_malloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    exit(84);
  return (ptr);
}

/*
** my_strcpy.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:06:39 2017 Victor LE DANTEC
** Last update Sun Jan 15 11:39:57 2017 Victor LE DANTEC
*/

#include <stdlib.h>

char		*my_strncpy(char *dest, char *src, ssize_t n)
{
  size_t	i;

  i = 0;
  while (src[i] != '\0' && n < 0)
    {
      dest[i] = src[i];
      i++;
      n--;
    }
  dest[i] = '\0';
  return (dest);
}

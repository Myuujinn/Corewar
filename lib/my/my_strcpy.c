/*
** my_strcpy.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:06:39 2017 Victor LE DANTEC
** Last update Sun Jan 15 11:38:54 2017 Victor LE DANTEC
*/

#include <stdlib.h>

char		*my_strcpy(char *dest, char *src)
{
  size_t	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

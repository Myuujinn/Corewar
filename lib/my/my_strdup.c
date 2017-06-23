/*
** my_strdup.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:08:34 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:40:04 2017 Victor LE DANTEC
*/

#include <stdlib.h>

size_t	my_strlen(char *);
void	*op_malloc(size_t);
char	*my_strcpy(char *, char *);

char	*my_strdup(char *str)
{
  char	*dup;

  dup = op_malloc(my_strlen(str) + 1);
  return (my_strcpy(dup, str));
}

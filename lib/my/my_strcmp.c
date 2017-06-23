/*
** my_strcmp.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:21:48 2017 Victor LE DANTEC
** Last update Thu Mar  9 13:20:07 2017 Victor LE DANTEC
*/

#include <stdlib.h>

size_t	my_strlen(char *);

ssize_t		my_strcmp(char *str1, char *str2)
{
  size_t	j;

  j = 0;
  while (str2[j] != '\0' && str1[j] != '\0' && str1[j] == str2[j])
    j++;
  return (str1[j] - str2[j]);
}

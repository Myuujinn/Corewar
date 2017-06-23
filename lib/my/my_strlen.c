/*
** my_strlen.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 20:53:30 2017 Victor LE DANTEC
** Last update Fri Jan  6 21:12:07 2017 Victor LE DANTEC
*/

#include <stdlib.h>

size_t	my_strlen(char *str)
{
  return ((*str != '\0') ? 1 + my_strlen(str + 1) : 0);
}

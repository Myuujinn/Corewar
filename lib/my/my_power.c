/*
** my_power.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 19:38:30 2017 Victor LE DANTEC
** Last update Fri Jan  6 19:46:45 2017 Victor LE DANTEC
*/

#include <stdlib.h>

ssize_t		my_power(ssize_t nb, ssize_t power)
{
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  return (nb * my_power(nb, power - 1));
}

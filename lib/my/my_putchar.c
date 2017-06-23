/*
** my_putchar.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 19:51:23 2017 Victor LE DANTEC
** Last update Fri Jan  6 19:52:07 2017 Victor LE DANTEC
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

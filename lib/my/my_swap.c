/*
** my_swap.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 21:39:03 2017 Victor LE DANTEC
** Last update Fri Jan  6 21:39:48 2017 Victor LE DANTEC
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *b = *a;
  *a = c;
}

/*
** my_put_nbr.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 19:52:32 2017 Victor LE DANTEC
** Last update Fri Jan  6 20:02:01 2017 Victor LE DANTEC
*/

void	my_putchar(char);

void	my_put_nbr(long long nb)
{
  int	i;

  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  i = nb % 10;
	  nb = (nb - i) / 10;
	  my_put_nbr(nb);
	  my_putchar(i + '0');
	}
      else
	my_putchar(nb + '0');
    }
}

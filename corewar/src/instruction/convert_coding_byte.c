/*
** convert_coding_byte.c for Projects in /home/Projects/Projects/convert_coding_byte.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Tue Mar 28 18:16:30 2017 Prenom Nom
** Last update Sun Apr  2 21:19:04 2017 Maxime Desforest
*/

void	byte_to_array(char bits[9], char c)
{
  int	i;

  i = 0;
  bits[8] = '\0';
  while (i < 8)
    {
      if (c & (1 << i))
	bits[7 - i] = '1';
      else
	bits[7 - i] = '0';
      i++;
    }
}

void	int_in_bytes(char bytes[4], int nbr)
{
  bytes[4] = '\0';
  bytes[0] = (nbr >> 24) & 0xFF;
  bytes[1] = (nbr >> 16) & 0xFF;
  bytes[2] = (nbr >> 8) & 0xFF;
  bytes[3] = nbr & 0xFF;
}

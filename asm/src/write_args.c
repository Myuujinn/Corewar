/*
** write_args.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Mar 29 00:14:33 2017 Victor LE DANTEC
** Last update Thu Mar 30 16:50:30 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

void	direct_label(t_champion *champ, short *direct,
		     char *index_mode, char *token)
{
  *direct = little_to_big_short
    (get_position_label
     (champ, token + 1) - champ->read_position);
  *index_mode = 1;
}

int	write_int(t_champion *champ, char *token, int *read)
{
  int	reg_value;

  if (token[0] == DIRECT_CHAR)
    token++;
  if (token[0] == LABEL_CHAR)
    reg_value = little_to_big_int
      (get_position_label
       (champ, token + 1) - champ->read_position);
  else
    reg_value = little_to_big_int(my_getnbr(token));
  if (write(champ->output_fd, &reg_value, sizeof(int)) <= 0)
    return (error_return(champ->name, "write failed\n"));
  *read += sizeof(int);
  return (EXIT_SUCCESS);
}

int	write_direct(t_champion *champ, char *token,
		     int *read, char index_mode)
{
  short	direct;
  int	direct2;

  if (token[0] == LABEL_CHAR)
    direct_label(champ, &direct, &index_mode, token);
  else
    direct = little_to_big_short(my_getnbr_short(token));
  if (index_mode == 0)
    {
      direct2 = little_to_big_int(my_getnbr(token));
      if (write(champ->output_fd, &direct2, sizeof(int)) <= 0)
	return (error_return(champ->name, "write failed\n"));
      *read += sizeof(int);
    }
  else
    {
      if (write(champ->output_fd, &direct, sizeof(short)) <= 0)
	return (error_return(champ->name, "write failed\n"));
      *read += sizeof(short);
    }
  return (EXIT_SUCCESS);
}

int	write_indirect(t_champion *champ, char *token, int *read)
{
  short	indirect;

  if (token[0] == LABEL_CHAR)
    indirect = little_to_big_short
      (get_position_label
       (champ, token + 1) - champ->read_position);
  else
    indirect = little_to_big_short(my_getnbr_short(token));
  if (write(champ->output_fd, &indirect, sizeof(short)) <= 0)
    return (error_return(champ->name, "write failed\n"));
  *read += sizeof(short);
  return (EXIT_SUCCESS);
}

int	write_register(t_champion *champ, char *token, int *read)
{
  char	reg;

  reg = (char)my_getnbr(token);
  if (write(champ->output_fd, &reg, sizeof(char)) <= 0)
    return (error_return(champ->name, "write failed\n"));
  *read += sizeof(char);
  return (EXIT_SUCCESS);
}

/*
** write_instructions.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Mar 28 17:39:59 2017 Victor LE DANTEC
** Last update Sun Apr  2 17:57:36 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "get_next_line.h"
#include "libmy.h"

int	write_args(t_champion *champ, char **tokens, int k, int *read)
{
  int	i;
  int	j;

  i = 0;
  while (tokens[++i] != 0)
    {
      j = identifier_token(tokens[i]);
      if (j == 3 && write_register(champ, tokens[i] + 1, read) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      else if ((j == 4 || j == 5) && identifier_token(tokens[i + 1]) == 3
	       && k == 1 && write_int(champ, tokens[i], read) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      else if (j == 4 && k != 2 && k != 8 && k != 9 && k != 10 && k != 11
	       && (!(identifier_token(tokens[i + 1]) == 3 && k == 1))
	       && write_direct(champ, tokens[i] + 1, read, 0) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      else if (j == 4 && (k == 2 || k == 8 || k == 9 || k == 10 || k == 11)
	       && (!(identifier_token(tokens[i + 1]) == 3 && k == 1))
	       && write_direct(champ, tokens[i] + 1, read, 1) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      else if (j == 5 && write_indirect(champ, tokens[i], read) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	write_instruc_codbyte(t_champion *champ, char **tokens,
			      int k, int *read)
{
  if (write(champ->output_fd, &op_tab[k].code, sizeof(char)) <= 0)
    return (error_return(champ->name, "write failed\n"));
  if (k != 0 && k != 8 && k != 11 && k != 14 &&
      write(champ->output_fd, get_coding_byte(tokens), sizeof(char)) <= 0)
    return (error_return(champ->name, "write failed\n"));
  if (k != 0 && k != 8 && k != 11 && k != 14)
    *read += sizeof(char);
  *read += sizeof(char);
  return (EXIT_SUCCESS);
}

int	write_instructions(t_champion *champ)
{
  char	*line;
  char	**tokens;
  int	k;
  int	read;

  while ((line = get_next_line(champ->input_fd)) != NULL)
    if (*(tokens = tokenizer(remove_comments(line))) != 0
	&& my_strcmp(*tokens, NAME_CMD_STRING) != 0
	&& my_strcmp(*tokens, COMMENT_CMD_STRING) != 0)
      {
	(identifier_token(*tokens) == 1) ? tokens++ : 0;
	if (*tokens != 0)
	  {
	    k = read = 0;
	    while (my_strcmp(*tokens, op_tab[k].mnemonique) != 0)
	      k++;
	    if (write_instruc_codbyte
		(champ, tokens, k, &read) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	    if (write_args(champ, tokens, k, &read) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	    champ->read_position += read;
	  }
      }
  return (EXIT_SUCCESS);
}

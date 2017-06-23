/*
** interpreter.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Mar 26 14:47:56 2017 Victor LE DANTEC
** Last update Sun Apr  2 18:16:31 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"
#include "get_next_line.h"

void	add_read_position(t_champion *champ, int type, int index, char *token)
{
  if (type == 3)
    champ->read_position += T_REG;
  else if (type == 4 && index != 2 && index != 8
	   && index != 9 && index != 10 && index != 11
	   && token[1] != LABEL_CHAR)
    champ->read_position += DIR_SIZE;
  else if (type == 4
	   && (index == 2 || index == 8
	       || index == 9 || index == 10 || index == 11
	       || token[1] == LABEL_CHAR))
    champ->read_position += IND_SIZE;
  else if (type == 5)
    champ->read_position += IND_SIZE;
}

int		has_good_type(t_champion *champ, char **tokens,
			      size_t index, int i)
{
  int		type;

  i = 0;
  while (tokens[++i] != NULL)
    {
      if ((type = identifier_token(tokens[i])) == 0 || type == 1 || type == 2)
	return (asm_error((ssize_t)champ->line, champ->name,
			  my_strcat(tokens[i], ": unexpected token")));
      if (type == 3 && has_arg(index, i - 1, T_REG) == 0)
	return (asm_error((ssize_t)champ->line, champ->name,
			  my_strcat(tokens[i], ": did not expect register")));
      if (type == 4 && has_arg(index, i - 1, T_DIR) == 0)
	return (asm_error((ssize_t)champ->line, champ->name,
			  my_strcat(tokens[i], ": did not expect direct")));
      if (type == 5 && has_arg(index, i - 1, T_IND) == 0)
	return (asm_error((ssize_t)champ->line, champ->name,
			  my_strcat(tokens[i], ": did not expect indirect")));
      if ((type == 4 || type == 5)
	  && identifier_token(tokens[i + 1]) == 3 && index == 1)
	champ->read_position += REG_SIZE;
      else
	add_read_position(champ, type, index, tokens[i]);
    }
  return (EXIT_SUCCESS);
}

int		process_line(t_champion *champ, char **tokens)
{
  size_t	index;
  int		i;

  i = index = 0;
  if (identifier_token(*tokens) != 2)
    return (asm_error((ssize_t)champ->line, champ->name,
		      my_strcat(*tokens, ": unknown instruction")));
  while (my_strcmp(*tokens, op_tab[index].mnemonique) != 0)
    index++;
  while (tokens[i + 1] != NULL)
    i++;
  if (i != op_tab[index].nbr_args)
    return (asm_error
	    ((ssize_t)champ->line, champ->name,
	     my_strcat("too much arguments for instruction ", *tokens)));
  if (index == 0 || index == 8 || index == 11 || index == 14)
    champ->read_position++;
  else
    champ->read_position += 2;
  if (has_good_type(champ, tokens, index, i) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	evaluator(t_champion *champ)

{
  char	*line;
  char	**tokens;

  while ((line = get_next_line(champ->input_fd)) != NULL)
    {
      champ->line++;
      tokens = tokenizer(remove_comments(line));
      if (*tokens != 0)
	{
	  if (identifier_token(*tokens) == 1)
	    {
	      if ((champ->labels = add_label
		   (champ, str_trunc(*tokens, my_strlen(*tokens) - 1),
		    champ->read_position)) == NULL)
		return (asm_error((ssize_t)champ->line, champ->name,
				  "multiple definition of same label"));
	      tokens++;
	    }
	  if (*tokens != 0 && process_line(champ, tokens) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

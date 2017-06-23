/*
** compile_champion.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar  9 14:50:32 2017 Victor LE DANTEC
** Last update Thu Mar 30 15:39:18 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"
#include "get_next_line.h"

int	read_champion(t_champion *champ)
{
  if (parse_header(&champ->cor_header,
		   champ->input_fd, champ->name, &champ->line) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  champ->read_position += sizeof(champ->cor_header);
  if (evaluator(champ) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	write_champion(t_champion *champ)
{
  int	size;

  if ((champ->output_fd = open(get_name_dot_cor(champ->name), O_RDWR | O_CREAT,
			       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (error_return(champ->name, "Couldn't create new binary file\n"));
  if (write(champ->output_fd, &champ->cor_header,
	    sizeof(champ->cor_header)) <= 0)
    return (error_return(champ->name, "Error writing header\n"));
  champ->read_position = sizeof(champ->cor_header);
  if (lseek(champ->input_fd, 0, SEEK_SET) == (off_t)-1)
    return (error_return(champ->name, "lseek failed\n"));
  if (write_instructions(champ) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  size = little_to_big_int(champ->read_position
			   - sizeof(champ->cor_header));
  if (lseek(champ->output_fd,
	    sizeof(champ->cor_header.magic) + sizeof(champ->cor_header.prog_name) + 3,
	    SEEK_SET)
      == (off_t)-1)
    return (error_return(champ->name, "lseek failed\n"));
  if (write(champ->output_fd, &size, sizeof(int)) <= 0)
    return (error_return(champ->name, "Error writing header size\n"));
  return (EXIT_SUCCESS);
}

int		check_labels(t_champion *champ)
{
  char		*line;
  char		**tokens;

  if (lseek(champ->input_fd, 0, SEEK_SET) == (off_t)-1)
    return (error_return(champ->name, "lseek failed\n"));
  champ->line = 0;
  while ((line = get_next_line(champ->input_fd)) != NULL)
    {
      champ->line++;
      tokens = tokenizer(remove_comments(line));
      while (*tokens != 0)
	{
	  if (process_labels_and_exists(champ, *tokens) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  tokens++;
	}
    }
  return (EXIT_SUCCESS);
}

int		compile_champion(char *name)
{
  t_champion	champ;

  champ.name = get_filename(name);
  champ.nb_labels = champ.input_fd =
    champ.output_fd = champ.read_position = champ.line = 0;
  if ((champ.input_fd = open(name, O_RDONLY)) < 0)
    return (error_return(champ.name, "No such file or directory\n"));
  if (read_champion(&champ) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (check_labels(&champ) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (write_champion(&champ) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

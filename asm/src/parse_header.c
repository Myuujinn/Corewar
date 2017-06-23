/*
** write_header.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar  9 15:41:51 2017 Victor LE DANTEC
** Last update Sun Apr  2 15:52:50 2017 Victor LE DANTEC
*/

#include "get_next_line.h"
#include "libmy.h"
#include "asm.h"

char		*parse_name_comment(char *str, char mode)
{
  size_t	i;
  char		*name;

  i = 0;
  while (str[i] != '\0' && str[i] != '\"')
    i++;
  if (str[i] == '\0' || str[i + 1] != '\0')
    return (NULL);
  name = op_malloc(sizeof(char) * (i + 2));
  if ((mode == 0 && i > PROG_NAME_LENGTH) || (mode == 1 && i > COMMENT_LENGTH))
    return (NULL);
  i = 0;
  while (str[i++] != '\"')
    name[i - 1] = str[i - 1];
  name[i - 1] = '\0';
  return (name);
}

int		get_name(int fd, char *name,
			 header_t *cor_header, size_t *line_nb)
{
  char		*line;
  char		valid_line;
  char		*valid_name;

  valid_line = 0;
  while (valid_line == 0)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (asm_error(*line_nb, name, "no correct name statement"));
      (*line_nb)++;
      line = remove_comments(line);
      if (line[0] != '\0' && empty_line(line) != 0)
	valid_line = 1;
    }
  while (*line != '\0' && (*line == ' ' || *line == '\t'))
    line++;
  if (*line == '\0')
    return (asm_error(*line_nb, name, "no correct name statement"));
  if (my_strcmp(clean_str(my_strsep(&line, "\"")), NAME_CMD_STRING) != 0)
    return (asm_error(*line_nb, name, "no correct name statement"));
  if ((valid_name = parse_name_comment(line, 0)) == NULL)
    return (asm_error(*line_nb, name, "no correct name statement"));
  my_strcpy(cor_header->prog_name, valid_name);
  return (EXIT_SUCCESS);
}

int	get_comment(int fd, char *name,
		    header_t *cor_header, size_t *line_nb)
{
  char		*line;
  char		valid_line;
  char		*valid_comment;

  valid_line = 0;
  while (valid_line == 0)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (asm_error(*line_nb, name, "no correct comment statement"));
      (*line_nb)++;
      line = remove_comments(line);
      if (line[0] != '\0' && empty_line(line) != 0)
	valid_line = 1;
    }
  while (*line != '\0' && (*line == ' ' || *line == '\t'))
    line++;
  if (*line == '\0')
    return (asm_error(*line_nb, name, "no correct comment statement"));
  if (my_strcmp(clean_str(my_strsep(&line, "\"")), COMMENT_CMD_STRING) != 0)
    return (asm_error(*line_nb, name, "no correct comment statement"));
  if ((valid_comment = parse_name_comment(line, 1)) == NULL)
    return (asm_error(*line_nb, name, "no correct comment statement"));
  my_strcpy(cor_header->comment, valid_comment);
  return (EXIT_SUCCESS);
}

int	parse_header(header_t *cor_header, int input_fd,
		     char *name, size_t *line)
{
  my_memset(cor_header, 0, sizeof(header_t));
  cor_header->magic = little_to_big_int(COREWAR_EXEC_MAGIC);
  my_memset(cor_header->prog_name, 0, PROG_NAME_LENGTH + 2);
  if (get_name(input_fd, name, cor_header, line) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  cor_header->prog_size = 0;
  my_memset(cor_header->comment, 0, COMMENT_LENGTH + 2);
  if (get_comment(input_fd, name, cor_header, line) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

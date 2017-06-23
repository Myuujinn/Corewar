/*
** label.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Mar 24 22:43:45 2017 Victor LE DANTEC
** Last update Wed Mar 29 16:20:14 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

int		process_labels_and_exists(t_champion *champ, char *token)
{
  if (identifier_token(token) == 4 && my_strlen(token) >= 2
      && token[1] == LABEL_CHAR)
    {
      if (token[2] == '\0')
	return (asm_error(champ->line, champ->name,
			  "empty label"));
      token += 2;
      if (get_position_label(champ, token) == -1)
	return (asm_error(champ->line, champ->name,
			  "undefined label"));
    }
  else if (identifier_token(token) == 5 && my_strlen(token) >= 1
	   && token[0] == LABEL_CHAR)
    {
      if (token[1] == '\0')
	return (asm_error(champ->line, champ->name,
			  "empty label"));
      token++;
      if (get_position_label(champ, token) == -1)
	return (asm_error(champ->line, champ->name,
			  "undefined label"));
    }
  return (EXIT_SUCCESS);
}

int		get_position_label(t_champion *champ, char *name)
{
  size_t	i;

  i = 0;
  while (i < champ->nb_labels
	 && my_strcmp(name, champ->labels[i].name) != 0)
    i++;
  if (i == champ->nb_labels)
    return (-1);
  return (champ->labels[i].position);
}

void		print_labels(t_champion *champ)
{
  size_t	i;

  i = 0;
  my_putstr_line("---- Current labels : ----");
  while (i < champ->nb_labels)
    {
      my_putstr_line(champ->labels[i].name);
      i++;
    }
}

t_label		*add_label(t_champion *champ, char *name,
			   size_t position)
{
  t_label	*new_labels;
  size_t	i;

  i = 0;
  while (i < champ->nb_labels
	 && my_strcmp(name, champ->labels[i].name) != 0)
    i++;
  if (i != champ->nb_labels)
    return (NULL);
  new_labels = op_malloc(sizeof(t_label) * (champ->nb_labels + 1));
  i = 0;
  while (i < champ->nb_labels)
    {
      new_labels[i].name = champ->labels[i].name;
      new_labels[i].position = champ->labels[i].position;
      i++;
    }
  new_labels[i].name = my_strdup(name);
  new_labels[i].position = position;
  champ->nb_labels++;
  return (new_labels);
}

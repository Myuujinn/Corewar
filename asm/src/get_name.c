/*
** get_name.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar 30 15:27:17 2017 Victor LE DANTEC
** Last update Thu Mar 30 19:50:57 2017 Victor LE DANTEC
*/

#include "libmy.h"

char		*get_name_dot_cor(char *name)
{
  size_t	i;

  i = my_strlen(name) - 1;
  if (i > 1 && name[i] == 's' && name[i - 1] == '.')
    name[i - 1] = '\0';
  return (my_strcat(name, ".cor"));
}

char		*get_filename(char *name)
{
  ssize_t	i;
  size_t	j;
  char		*newname;

  i = my_strlen(name) - 1;
  while (i > 0 && name[i] != '/')
    i--;
  if (i == 0)
    return (my_strdup(name));
  i++;
  j = 0;
  newname = op_malloc(sizeof(char) * my_strlen(name) + 1);
  while (name[i] != '\0')
    newname[j++] = name[i++];
  newname[j] = '\0';
  return (newname);
}

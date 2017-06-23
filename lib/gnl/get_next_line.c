/*
** get_next_line.c for  in /home/maxime/Repo/CPE_2016_matchstick/src/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Fri Feb 24 15:28:00 2017 Maxime Desforest
** Last update Tue Apr  4 22:21:42 2017 Victor LE DANTEC
*/

#include "get_next_line.h"

char	*my_realloc(char* ptr, size_t size)
{
  char	*temp;
  int	i;

  temp = ptr;
  ptr = op_malloc(size);
  i = 0;
  while (temp[i])
    {
      ptr[i] = temp[i];
      i++;
    }
  my_free(temp);
  temp = NULL;
  return (ptr);
}

char		get_char(const int fd)
{
  static char	buff[READ_SIZE];
  static char	*ptr_buff;
  static int	len = 0;
  char		c;

  if (len == 0)
    {
      len = read(fd, buff, READ_SIZE);
      ptr_buff = (char *)&buff;
      if (len == 0)
	return (0);
    }
  c = *ptr_buff;
  ptr_buff++;
  len--;
  return (c);
}

char	*get_next_line(const int fd)
{
  char	c;
  char	*str;
  int	len;

  len = 0;
  str = op_malloc(READ_SIZE + 1);
  if (str == NULL)
    return (0);
  c = get_char(fd);
  while (c != '\n' && c != '\0')
    {
      str[len] = c;
      c = get_char(fd);
      len++;
      if (len % (READ_SIZE + 1) == 0)
	str = my_realloc(str, len + READ_SIZE + 1);
    }
  str[len] = 0;
  if (c == 0 && str[0] == 0)
    return (0);
  return (str);
}

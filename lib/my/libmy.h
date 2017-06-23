/*
** libmy.h for Libmy in /home/myujinn/PSU/PSU_2016_navy
**
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
**
** Started on  Mon Jan 30 15:21:00 2017 Victor LE DANTEC
** Last update Wed Mar 29 00:46:07 2017 Victor LE DANTEC
*/

#pragma once

# include <stdlib.h>

typedef struct		s_malloc
{
  int			size;
  long unsigned int	*ptrs;
}			t_malloc;

void		*my_calloc(size_t);
void		*my_malloc(size_t);
void		my_free(void *);
void		*my_memset(void *, int, size_t);
void		*my_memcpy(void *, void *, size_t);

void		my_put_adress(long);
void		my_putchar(char);
void		my_put_nbr_base(ssize_t, char *);
void		my_put_nbr(long long);
void		my_putstr(char *);
void		my_putstr_line(char *);
void		my_puterr(char *);

ssize_t		my_power(ssize_t, ssize_t);
ssize_t		my_getnbr(char *);
short		my_getnbr_short(char *);
void		my_show_wordtab(char **);
char		*my_strcat(char *, char *);
ssize_t		my_strcmp(char *, char *);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
size_t		my_strlen(char *);
char		*my_strsep(char **, char *);
char		*my_strstr(char *, char *);
ssize_t		my_strncmp(char *, char *, size_t);
char		*my_strncpy(char *, char *, ssize_t);
void		my_swap(int *, int *);
char		**my_tabdup(char **);

void		*op_malloc(size_t);
void		op_free();
t_malloc	*get_array();

/*
** asm.h for asm in /home/victor/ASM/CPE_2016_corewar
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar  9 13:25:08 2017 Victor LE DANTEC
** Last update Thu Mar 30 16:47:14 2017 Victor LE DANTEC
*/

#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"

#undef EXIT_FAILURE
#define EXIT_FAILURE	84

typedef struct		s_label
{
  char			*name;
  size_t		position;
}			t_label;

typedef struct		s_champion
{
  char			*name;
  int			input_fd;
  int			output_fd;
  header_t		cor_header;
  t_label		*labels;
  size_t		nb_labels;
  size_t		read_position;
  size_t		line;
}			t_champion;

void			error_msg(char *, char);
int			asm_error(ssize_t, char *, char *);
int			error_return(char *, char *);

int			empty_line(char *);
char			*clean_str(char *);
char			*remove_comments(char *);
char			*str_trunc(char *, size_t);
int			char_in_string(char, char *);

int			little_to_big_int(int);
short			little_to_big_short(short);

t_label			*add_label(t_champion *, char *, size_t);
int			get_position_label(t_champion *, char *);
int			process_labels_and_exists(t_champion *, char *);

int			identifier_token(char *);
char			**tokenizer(char *);
int			evaluator(t_champion *);
int			write_instructions(t_champion *);
int			compile_champion(char *);
int			parse_header(header_t *, int, char *, size_t *);

void			print_tokens(char **);
void			print_labels(t_champion *);

int			has_arg(int, int, int);
char			*get_coding_byte(char **);

int			write_int(t_champion *, char *, int *);
int			write_register(t_champion *, char *, int *);
int			write_direct(t_champion *, char *, int *, char);
int			write_indirect(t_champion *, char *, int *);

char			*get_filename(char *);
char			*get_name_dot_cor(char *);

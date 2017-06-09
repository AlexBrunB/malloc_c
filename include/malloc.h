/*
** malloc.h for malloc in /home/abrun/delivery/Tek2/Memoire/PSU_2016_malloc/
**
** Made by Alexandre Brun
** Login   <alexandre.brun@epitech.eu>
**
** Started on  Mon Jan 30 11:20:19 2017 Alexandre Brun
** Last update mer. févr. 08 10:44:32 2017 Arthur CORUBLE
*/

#ifndef MALLOC_H
# define MALLOC_H

#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct		s_block
{
  size_t		size;
  unsigned		is_free;
  struct s_block	*next;
}			t_block;

extern t_block		*g_start;
extern t_block		*g_end;
extern pthread_mutex_t	g_lock;
t_block			*free_block(size_t);
void			*malloc(size_t);
void			free(void *);
void			*realloc(void *, size_t);
t_block			*malloc_2(void *, t_block *, size_t);
void			free_2();
void			my_putnbr_base(uintptr_t, char*);
void			show_alloc_mem();

#endif /* !MALLOC_H */

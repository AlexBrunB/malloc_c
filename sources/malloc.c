/*
** malloc.c for malloc in /home/acoruble/ProjetsC/PSU_2016_malloc
**
** Made by Arthur Coruble
** Login   <arthur.coruble@epitech.eu>
**
** Started on  lun. janv. 30 16:30:54 2017 Arthur Coruble
** Last update jeu. févr. 09 09:54:40 2017 Arthur CORUBLE
*/

#include "../include/malloc.h"

t_block		*g_start;
t_block		*g_end;
pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

t_block		*free_block(size_t size)
{
  t_block	*actual;

  actual = g_start;
  while (actual)
    {
      if (actual->is_free && actual->size >= size)
	return (actual);
      actual = actual->next;
    }
  return (NULL);
}

t_block	*malloc_2(void *block, t_block *header, size_t size)
{
  header = block;
  header->size = size;
  header->is_free = 0;
  header->next = NULL;
  if (!g_start)
    g_start = header;
  if (g_end)
    g_end->next = header;
  g_end = header;
  return (header);
}

void		*malloc(size_t size)
{
  size_t	total_size;
  void	       	*block;
  t_block	*header;

  if (!size)
    return (NULL);
  pthread_mutex_lock(&g_lock);
  header = free_block(size);
  if (header)
    {
      header->is_free = 0;
      pthread_mutex_unlock(&g_lock);
      return (void*)(header + 1);
    }
  total_size = sizeof(t_block) + size;
  block = sbrk(total_size);
  if (block == (void*) -1)
    {
      pthread_mutex_unlock(&g_lock);
      return (NULL);
    }
  pthread_mutex_unlock(&g_lock);
  header = malloc_2(block, header, size);
  return (void*)(header + 1);
}

void	free_2()
{
  t_block *tmp;

  if (g_start == g_end)
    {
      g_start = NULL;
      g_end = NULL;
    }
  else
    {
      tmp = g_start;
      while (tmp)
	{
	  if (tmp->next == g_end)
	    {
	      tmp->next = NULL;
	      g_end = tmp;
	    }
	  tmp = tmp->next;
	}
    }
}

void		free(void *block)
{
  t_block	*header;
  void	       	*pointbreak;

  if (!block)
    return;
  pthread_mutex_lock(&g_lock);
  header = (t_block*)block - 1;
  pointbreak = sbrk(0);
  if ((char *)block + header->size == pointbreak)
    {
      free_2();
      sbrk(0 - sizeof(t_block) - header->size);
      pthread_mutex_unlock(&g_lock);
      return;
    }
  pthread_mutex_unlock(&g_lock);
  header->is_free = 1;
}

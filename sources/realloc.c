/*
** realloc.c for malloc in /home/acoruble/Epitech/Tek2/Memoire/PSU_2016_malloc/sources
**
** Made by Arthur CORUBLE
** Login   <arthur.coruble@epitech.eu>
**
** Started on  ven. févr. 03 12:12:34 2017 Arthur CORUBLE
** Last update mer. févr. 08 10:38:30 2017 Arthur CORUBLE
*/

#include "../include/malloc.h"

void		*realloc(void *block, size_t size)
{
  t_block	*header;
  void		*result;

  if (!block || !size)
    return (malloc(size));
  header = (t_block*)block - 1;
  if (header->size >= size)
    return (block);
  result = malloc(size);
  if (result)
    {
      memcpy(result, block, header->size);
      free(block);
    }
  return (result);
}

void	show_alloc_mem()
{
  t_block	*temp;
  uintptr_t	break_pos;

  temp = g_start;
  break_pos = (uintptr_t)sbrk(0);
  write(1, "break : 0x", 10);
  my_putnbr_base(break_pos, "0123456789abcdef");
  write(1, "\n", 1);
  while (temp)
    {
      write(1, "0x", 2);
      my_putnbr_base((uintptr_t)temp, "0123456789abcdef");
      write(1, " - 0x", 5);
      my_putnbr_base(((uintptr_t)(temp) + (uintptr_t)(temp->next)),
		     "0123456789abcdef");
      write(1, " : ", 3);
      my_putnbr_base((uintptr_t)temp->size, "0123456789");
      write(1, " bytes\n", 7);
      temp = temp->next;
    }
}

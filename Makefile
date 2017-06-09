##
## Makefile for Makefile in /home/abrun/delivery/Tek2/Memoire/PSU_2016_malloc
##
## Made by Alexandre Brun
## Login   <abrun@epitech.net>
##
## Started on  Tue Jan 31 16:15:50 2017 Alexandre Brun
## Last update lun. févr. 06 13:20:10 2017 Arthur CORUBLE
##

CC	= gcc

CFLAGS	= -fPIC -shared -Wall -Wextra

RM	=	rm -f

TARGET	=	libmy_malloc.so

SRC	=	sources/malloc.c	\
		sources/realloc.c

OBJ	=	$(SRC:.c=.o)

all:		$(TARGET)

$(TARGET):	$(OBJ)

		$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	$(RM) sources/*.o

fclean:	clean
	$(RM) $(TARGET)

re:	fclean all

.PHONY: all clean fclean re

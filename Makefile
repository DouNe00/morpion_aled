##
## Makefile for  in /home/cabane_g/rendu/Piscine_C_J10/do-op
##
## Made by cabanes gabriel
## Login   <cabane_g@epitech.net>
##
## Started on  Mon Oct 12 09:17:53 2015 cabanes gabriel
## Last update Thu Dec 10 18:05:59 2015 cabanes gabriel
##

CC	= gcc -g

RM	= rm -f

CFLAGS	= -I./include/ -w -Wall -Wextra -pedantic -g
LIB	= -lncurses

NAME	= morpion

SRCS	= display_game.c \

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

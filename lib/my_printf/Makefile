##
## Makefile for Makefile in /home/delmon_m/rendu/Piscine_C_J10/lib/my
## 
## Made by MD MD
## Login   <delmon_m@epitech.net>
## 
## Started on  Fri Oct  9 12:16:11 2015 MD MD
## Last update Fri Nov 20 14:00:59 2015 cabanes gabriel
##

SRC =	my_putchar_p.c \
	my_putnbr_p.c \
	my_putstr_p.c \
	my_strlen_p.c \
	display.c \
	d_to_u.c \
	my_printf.c \
	my_putnbr_base.c \
	o_to_X.c \
	p_and_S.c

NAME =	myprintf.a

OBJ =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp myprintf.a ../
	cp my_struct.h ../../include
	cp my_printf.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	 rm -f $(NAME)
	 rm -f ../myprintf.a
	 rm -f ../../include/my_struct.h
	 rm -f ../../include/my_printf.h

re: fclean all

.PHONY: all clean fclean re

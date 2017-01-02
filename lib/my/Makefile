##
## Makefile for Makefile in /home/delmon_m/rendu/Piscine_C_J10/lib/my
## 
## Made by MD MD
## Login   <delmon_m@epitech.net>
## 
## Started on  Fri Oct  9 12:16:11 2015 MD MD
## Last update Tue Nov  3 16:06:12 2015 cabanes gabriel
##

SRC =	my_putchar.c \
	my_isneg.c \
	my_put_nbr.c \
	my_swap.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_sort_int_tab.c \
	my_power_rec.c \
	my_square_root.c \
	my_is_prime.c \
	my_find_prime_sup.c \
	my_strcpy.c \
	my_strncpy.c \
	my_revstr.c \
	my_strstr.c \
	my_strcmp.c \
	my_strncmp.c \
	my_strupcase.c \
	my_strlowcase.c \
	my_strcapitalize.c \
	my_str_isalpha.c \
	my_str_isnum.c \
	my_str_islower.c \
	my_str_isupper.c \
	my_str_isprintable.c \
	my_showstr.c \
	my_showmem.c \
	my_strcat.c \
	my_strncat.c \
	my_strdup.c \
	sum_stdarg.c \
	disp_stdarg.c

NAME =	libmy.a

OBJ =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp libmy.a ../
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	 rm -f $(NAME)
	 rm -f ../libmy.a
	 rm -f ../../include/my.h

re: fclean all

.PHONY: all clean fclean re

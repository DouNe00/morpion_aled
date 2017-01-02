/*
** my_printf.h for  in /home/cabane_g/rendu/B1_Unix_System_Programming/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Wed Nov  4 14:48:58 2015 cabanes gabriel
** Last update Mon Nov 16 11:26:56 2015 cabanes gabriel
*/

#include <stdarg.h>
#include "my_struct.h"
#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

int	distrib(char *str, int i, t_params *stock, va_list ap);
int	number(va_list ap);
int	charac(va_list ap);
int	string(va_list ap);
int	pointer(va_list ap);
int	unsign(va_list ap);
int	my_printf(char *str, ...);
int	octal(va_list ap);
int	binary(va_list ap);
int	hexa_less(va_list ap);
int	hexa_upp(va_list ap);
int	non_printable(va_list ap);
void	put_some_things(char *str, int i);
int	my_putchar_p(char c);
int	my_putstr_p(char *str);
int	my_putnbr_p(int nb);

#endif /* MY_PRINTF_H_ */

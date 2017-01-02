/*
** disp_stdarg.c for  in /home/cabane_g/rendu/PSU_2015_my_printf_bootstap
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Tue Nov  3 15:46:33 2015 cabanes gabriel
** Last update Wed Nov  4 13:59:16 2015 cabanes gabriel
*/

#include <stdarg.h>

int		disp_stdarg(char *s, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == 'c')
	my_putchar(va_arg(ap, int));
      else if (s[i] == 's')
	my_putstr(va_arg(ap, char*));
      else if (s[i] == 'i')
	my_put_nbr(va_arg(ap, int));
      my_putchar('\n');
      i++;
    }
  va_end(ap);
  return (0);
}

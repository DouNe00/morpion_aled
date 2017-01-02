/*
** my_putstr.c for my_putstr in /home/delmon_m/rendu/Piscine_C_J04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Thu Oct  1 11:26:05 2015 MD MD
** Last update Mon Nov 16 11:31:24 2015 cabanes gabriel
*/

int	my_putstr_p(char *str)
{
  int	i;

  i = 0;
  while (*str)
    {
      i = i + my_putchar_p(*str);
      str = str + 1;
    }
  return (i);
}

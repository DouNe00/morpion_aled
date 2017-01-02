/*
** my_putstr.c for my_putstr in /home/delmon_m/rendu/Piscine_C_J04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Thu Oct  1 11:26:05 2015 MD MD
** Last update Thu Oct  1 11:42:56 2015 MD MD
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

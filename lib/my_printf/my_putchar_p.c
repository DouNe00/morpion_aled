/*
** my_putchar.c for my_putchar in /home/delmon_m/rendu/lib/my
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Tue Oct  6 09:39:56 2015 MD MD
** Last update Mon Nov 16 10:46:59 2015 cabanes gabriel
*/

int	my_putchar_p(char c)
{
  write(1, &c, 1);
  return (1);
}

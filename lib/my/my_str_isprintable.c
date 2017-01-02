/*
** my_str_isprintable.c for my_str_isprintable in /home/delmon_m/rendu/Piscine_C_J06/ex_15
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 23:00:18 2015 MD MD
** Last update Mon Oct  5 23:06:22 2015 MD MD
*/

int	my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] <= 126)
        {
          i = i + 1;
        }
      else
        {
          return (0);
        }
    }
  return (1);
}

/*
** my_str_isnum.c for my_str_isnum in /home/delmon_m/rendu/Piscine_C_J06/ex_12
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 22:43:21 2015 MD MD
** Last update Mon Oct  5 23:16:41 2015 MD MD
*/

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
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

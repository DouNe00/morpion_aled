/*
** my_str_islower.c for my_str_islower in /home/delmon_m/rendu/Piscine_C_J06/ex_13
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 22:52:58 2015 MD MD
** Last update Mon Oct  5 22:56:24 2015 MD MD
*/

int	my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
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

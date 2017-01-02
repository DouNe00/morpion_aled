/*
** my_str_isupper.c for my_str_isupper in /home/delmon_m/rendu/Piscine_C_J06/ex_14
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 22:58:20 2015 MD MD
** Last update Mon Oct  5 22:59:35 2015 MD MD
*/

int	my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
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

/*
** my_strlowcase.c for my_strlowcase in /home/delmon_m/rendu/Piscine_C_J06/ex_09
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 18:18:07 2015 MD MD
** Last update Mon Oct  5 18:19:17 2015 MD MD
*/

char	*my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
        {
          str[i] = str[i] + 32;
        }
      i = i + 1;
    }
  return (str);
}

/*
** my_revstr.c for my_revstr in /home/delmon_m/rendu/Piscine_C_J06/ex_04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 13:23:22 2015 MD MD
** Last update Tue Oct  6 10:03:31 2015 MD MD
*/

char	*my_revstr(char *str)
{
  int   i;
  int   j;
  char  c;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}

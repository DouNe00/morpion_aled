/*
** my_strstr.c for my_strstr in /home/delmon_m/rendu/Piscine_C_J06/ex_05
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 13:36:52 2015 MD MD
** Last update Mon Oct  5 18:41:07 2015 MD MD
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  char	*returned;

  i = 0;
  j = 0;
  if (to_find[0] == '\0')
    {
      return (str);
    }
  while (str[i] != '\0')
    {
      while (str[i] == to_find[j])
	{
	  j = j + 1;
	  i = i + 1;
	  if (to_find[j] == '\0')
	    {
	      returned = (&str[i - j]);
	      return (returned);
	    }
	}
      i = i - j + 1;
      j = 0;
    }
  return (0);
}

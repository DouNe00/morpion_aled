/*
** my_str_isalpa.c for my_str_isalpha in /home/delmon_m/rendu/Piscine_C_J06/ex_11
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 22:26:28 2015 MD MD
** Last update Mon Oct  5 22:41:09 2015 MD MD
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
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

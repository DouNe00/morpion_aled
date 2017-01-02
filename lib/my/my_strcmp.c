/*
** my_strcmp.c for my_strcmp in /home/delmon_m/rendu/Piscine_C_J06/ex_06
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 14:55:31 2015 MD MD
** Last update Tue Oct  6 17:15:33 2015 MD MD
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	dif;

  i = 0;
  dif = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	{
	  dif = s1[i] - s2[i];
	  return (dif);
	}
      i = i + 1;
    }
  return (dif);
}

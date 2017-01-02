/*
** my_strlen.c for my_strlen.c in /home/delmon_m/rendu/Piscine_C_J04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Thu Oct  1 11:44:22 2015 MD MD
** Last update Thu Oct  1 12:15:23 2015 MD MD
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str[len] != '\0')
    {
      len = len + 1;
    }
  return (len);
}

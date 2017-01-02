/*
** my_strdup.c for my_strdup in /home/delmon_m/rendu/Piscine_C_J08/ex_01
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Wed Oct  7 09:31:39 2015 MD MD
** Last update Wed Oct  7 09:51:55 2015 MD MD
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;
  int	tall;

  tall = my_strlen(src);
  dest = malloc(tall + 1);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

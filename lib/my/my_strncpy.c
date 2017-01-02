/*
** my_strncpy.c for my_strncpy in /home/delmon_m/rendu/Piscine_C_J06/ex_03
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 11:44:15 2015 MD MD
** Last update Tue Oct  6 10:02:29 2015 MD MD
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while ((i < nb) && (src[i] != '\0')) 
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i < nb)
    {
      dest[i] = '\0';
    }
  return (dest);
}

/*
** my_strcapitalize.c for my_strcapitalize in /home/delmon_m/rendu/Piscine_C_J06/ex_10
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 18:20:50 2015 MD MD
** Last update Mon Oct  5 21:44:26 2015 MD MD
*/

int	is_word(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      return (1);
    }
  else if (c >= '0' && c <= '9')
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

int	is_lower(char c)
{
  return (c >= 'a' && c <= 'z');
}
	
char	*my_strcapitalize(char *str)
{
  int	i;
  char c;

  i = 0;
  if (!str)
    {
      return (0);
    }
  while (str[i] != '\0')
    {
      if (is_lower(str[i]))
	{
	  if (i == 0)
	    {
	      str[i] = str[i] - 32;
	    }
	  else if (i > 0 && is_word(str[i - 1]) == 0)
	    {
	      str[i] = str[i] - 32;
	    }
	}
	i = i + 1;
    }
  return (str);
}

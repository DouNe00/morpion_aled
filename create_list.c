/*
** create_list.c for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Mon Nov 30 13:59:12 2015 cabanes gabriel
** Last update Thu Dec 10 18:10:37 2015 cabanes gabriel
*/

#include <stdlib.h>
#include "list.h"

int		my_putin_list(t_list **list, t_list **lastelem, char *av, int i)
{
  t_list	*newelem;

  if ((newelem = malloc(sizeof(t_list))) == NULL)
      return (1);
  newelem->underline = ((i == 0) ?  1 : 0);
  newelem->first = ((i == 0) ?  1 : 0);
  newelem->select = 0;
  newelem->data = av;
  newelem->next = *list;
  if (newelem->next != NULL)
    newelem->next->prev = newelem;
  else
    *lastelem = newelem;
  *list = newelem;
  return (0);
}

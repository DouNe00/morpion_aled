/*
** manage_bonus.c for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Thu Dec 10 16:51:46 2015 cabanes gabriel
** Last update Thu Dec 10 17:13:13 2015 cabanes gabriel
*/

#include <ncurses.h>
#include "list.h"

t_list		*key_left(t_list *tmp, int key)
{
  int		i;

  i = 0;
  if (key == KEY_LEFT)
    {
      tmp->underline = 0;
      while (i++ < getmaxy(stdscr) - 2)
	tmp = tmp->prev;
      tmp->underline = 1;
    }
  return (tmp);
}

t_list		*key_right(t_list *tmp, int key)
{
  int		i;

  i = 0;
  if (key == KEY_RIGHT)
    {
      tmp->underline = 0;
      while (i++ < getmaxy(stdscr) - 2)
	tmp = tmp->next;
      tmp->underline = 1;
    }
  return (tmp);
}

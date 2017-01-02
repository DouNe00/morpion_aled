/*
** manage_printing.c for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Thu Dec  3 15:38:40 2015 cabanes gabriel
** Last update Fri Dec 11 16:29:02 2015 cabanes gabriel
*/

#include <ncurses.h>
#include "list.h"

t_list          *key_down(t_list *tmp, int key)
{
  if (key == KEY_DOWN)
    {
      tmp->underline = 0;
      tmp = tmp->next;
      tmp->underline = 1;
    }
  return (tmp);
}

t_list          *key_up(t_list *tmp, int key)
{
  if (key == KEY_UP)
    {
      tmp->underline = 0;
      tmp = tmp->prev;
      tmp->underline = 1;
    }
  return (tmp);
}

t_list		*space(t_list *tmp, int key)
{
  if (key == 32)
    {
      tmp->select = ((tmp->select) ? 0 : 1);
      tmp->underline = 0;
      tmp = tmp->next;
      tmp->underline = 1;
    }
  return (tmp);
}

t_list		*delete(t_list *tmp, int key, t_list **head)
{
  if (key == KEY_DC || key == KEY_BACKSPACE)
    {
      if (tmp->first == 1)
        tmp->next->first = 1;
      if (tmp->next->data == tmp->data)
        {
          endwin();
          exit(0);
        }
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      free(tmp);
      tmp = tmp->next;
      tmp->underline = 1;
      erase();
    }
  return (tmp);
}

/*
** display_argv.c for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Mon Nov 30 13:42:51 2015 cabanes gabriel
** Last update Sun Dec 13 19:59:37 2015 cabanes gabriel
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void	display(t_list *list, int ac, int y, int x)
{
  box(stdscr, 0, 0);
  while (list->first != 1)
    list = list->next;
  while (list->next->first != 1)
    {
      if (y >= getmaxy(stdscr) - 1)
      	{
      	  y = 1;
	  x += change_col(list, getmaxy(stdscr), x) + 1;
	}
      if (x + my_strlen(list->data) > getmaxx(stdscr))
	{
	  endwin();
	  write(2, "Not enough space to display arguments\n", 39);
	  exit(0);
	}
      ((list->select == 1) ? attron(A_REVERSE) : attron(A_NORMAL));
      ((list->underline == 1) ? attron(A_UNDERLINE) : attron(A_NORMAL));
      mvprintw(y++, x, "%s", list->data);
      attroff(A_UNDERLINE | A_REVERSE);
      list = list->next;
    }
  display_last(list, y, x, ac);
}

int	change_col(t_list *list, int y, int x)
{
  int	bigger;
  int	cmp;

  cmp = y;
  bigger = 0;
  while (cmp > 0)
    {
      if (my_strlen(list->data) > bigger)
	bigger = my_strlen(list->data);
      list = list->prev;
      cmp--;
    }
  return (bigger);
}

void	display_last(t_list *list, int y, int x, int ac)
{
  if (y >= getmaxy(stdscr) - 1)
    {
      y = 1;
      x += change_col(list, getmaxy(stdscr), x) + 1;
    }
  if (x + my_strlen(list->data) > getmaxx(stdscr))
    {
      endwin();
      write(2, "Not enough space to display arguments\n", 39);
      exit(0);
    }
  ((list->select == 1) ? attron(A_REVERSE) : attron(A_NORMAL));
  ((list->underline == 1) ? attron(A_UNDERLINE) : attron(A_NORMAL));
  mvprintw(y++, x, "%s", list->data);
  attroff(A_REVERSE | A_UNDERLINE);
}

t_list		**manage_print(t_list **list, int key, int ac, t_list **head)
{
  t_list	*tmp;

  tmp = *list;
  tmp = key_down(tmp, key);
  tmp = key_up(tmp, key);
  tmp = key_left(tmp, key);
  tmp = key_right(tmp, key);
  tmp = space(tmp, key);
  tmp = delete(tmp, key, &head);
  display(tmp, ac, 1, 1);
  *list = tmp;
  return (*list);
}

t_list	*move_inlist(t_list *list, int ac, t_list **head)
{
  int	key;

  key = 0;
  while (key != 27 && key != 10)
    {
      key = getch();
      if (key == 27)
	{
	  endwin();
	  exit(0);
	}
      erase();
      list = manage_print(&list, key, ac, &head);
      refresh();
    }
  while (list->first != 1)
    list = list->prev;
  return (list);
}

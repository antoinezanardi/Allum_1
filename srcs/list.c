/*
** init.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 09:44:19 2015 Antoine Zanardi
** Last update Tue Feb 10 18:46:23 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"allum1.h"
#include	"my.h"

int		end_game(t_list *list, char *str)
{
  if (list->prev == NULL && list->next == NULL && list->nombre == 1)
    {
      mk_clear();
      my_putstr("|\n");
      my_putstr(str);
      my_putchar(' ');
      my_putstr("wins ! Fatality !\n");
      return (0);
    }
  return (1);
}

void		fill_my_list(t_list **list, int row)
{
  unsigned int	nombre;
  int		compt_row;

  nombre = 1;
  compt_row = 0;
  while (compt_row < row)
    {
      add_bot_list(list, nombre);
      compt_row++;
      nombre += 2;
    }
}

void		change_line(t_list **list, t_choice *player, int *row)
{
  t_list	*tmp;
  int		compt_row;

  compt_row = 1;
  tmp = *list;
  while (compt_row < player->row)
    {
      compt_row++;
      tmp = tmp->next;
    }
  tmp->nombre = tmp->nombre - player->number;
  if (tmp->nombre == 0)
    {
      remove_elem_list(list, player->row);
      (*row)--;
    }
}

void		remove_elem_list(t_list **list, int row_choose)
{
  int		compt_row;
  t_list	*save;
  t_list	*tmp;

  compt_row = 1;
  tmp = *list;
  while (compt_row < row_choose)
    {
      compt_row++;
      tmp = tmp->next;
    }
  if (tmp->prev == NULL)
    {
      tmp->next->prev = NULL;
      (*list) = tmp->next;
    }
  else if (tmp->next == NULL)
    tmp->prev->next = NULL;
  else
    {
      save = tmp->next;
      tmp->prev->next = tmp->next;
      save->prev = tmp->prev;
    }
  free(tmp);
}

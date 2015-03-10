/*
** easy_ia.c for easy in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 14:58:21 2015 Antoine Zanardi
** Last update Tue Feb 10 18:34:12 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"allum1.h"
#include	"my.h"

void		bigger_row(t_list **list, t_choice *easy)
{
  int		compt;
  unsigned int	low;
  int		bool;
  t_list	*tmp;

  tmp = *list;
  bool = 0;
  compt = 1;
  while (tmp != NULL)
    {
      if (bool == 0)
	{
	  easy->row = compt;
	  low = tmp->nombre;
	  bool = 1;
	}
      else if (low < tmp->nombre)
	{
	  easy->row = compt;
	  low = tmp->nombre;
	}
      compt++;
      tmp = tmp->next;
    }
  free(tmp);
}

void		minus_easy(t_list **list, t_choice *easy)
{
  t_list	*tmp;
  int		compt_row;

  tmp = *list;
  compt_row = 1;
  while (compt_row < easy->row)
    {
      tmp = tmp->next;
      compt_row++;
    }
  if (tmp->nombre == 1)
    easy->number = 1;
  else if (tmp->nombre % 2 == 0)
    easy->number = 1;
  else if (tmp->nombre % 2 == 1)
    easy->number = 2;
}

int		easy_ia(t_list **list, int *row)
{
  t_choice	easy;

  mk_clear();
  my_show_list(*list);
  my_putstr("Easybot is loading its tactic\n");
  usleep(2000000);
  bigger_row(list, &easy);
  minus_easy(list, &easy);
  change_line(list, &easy, row);
  if (end_game(*list, "Easy_bot") == 0)
    return (0);
  return (1);
}

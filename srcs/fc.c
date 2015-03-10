/*
** fc.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 09:51:29 2015 Antoine Zanardi
** Last update Tue Feb 10 13:44:40 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"allum1.h"
#include	"my.h"

int		bigger_line(t_list **list)
{
  t_list	*tmp;
  int		bool;
  unsigned int	nb;

  bool = 0;
  tmp = *list;
  while (tmp != NULL)
    {
      if (bool == 0)
	{
	  nb = tmp->nombre;
	  bool = 1;
	}
      else
	if (nb < tmp->nombre)
	  nb = tmp->nombre;
      tmp = tmp->next;
    }
  free(tmp);
  return (nb);
}

int		str_is_mode(char *str)
{
  if (str[0] == '1' && str[1] == '\0')
    return (0);
  if (str[0] == '2' && str[1] == '\0')
    return (0);
  my_putstr("Veuillez choisir un mode valide\n");
  return (1);
}

int		str_is_posi(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	{
	  my_putstr("This is not a valid number\n\n");
	  return (1);
	}
    }
  return (0);
}

int		compare_nb(char *str, int row)
{
  if (my_getnbr(str) > row)
    {
      my_putstr("Please don't go over the number of line max\n\n");
      return (1);
    }
  if (my_getnbr(str) == 0)
    {
      my_putstr("There is no line 0\n\n");
      return (1);
    }
  return (0);
}

int		compare_a(char *str, int match, t_list *list)
{
  if (my_getnbr(str) > match)
    {
      my_putstr("Please don't pick over the number of matchstick max\n\n");
      return (1);
    }
  if (my_getnbr(str) == 0)
    {
      my_putstr("Pick at least one matchstick\n\n");
      return (1);
    }
  if (list->next == NULL && list->prev == NULL && my_getnbr(str) == match)
    {
      my_putstr("You can't pick too much matchstick on the last line left\n\n");
      return (1);
    }
  return (0);
}

/*
** ia_exp_boyard.c for boyard in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 19:46:54 2015 Antoine Zanardi
** Last update Mon Feb  9 20:15:24 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"allum1.h"
#include	"my.h"

int		final_choice(int allum)
{
  if (allum == 2)
    return (1);
  else if (allum == 3)
    return (2);
  else if (allum == 4)
    return (3);
  return (1);
}

int		analyse_choice(int choice)
{
  int		cst;

  cst = 4 - choice;
  return (cst);
}

int		ia_exp_boyard(unsigned int *allum, int choice)
{
  static int	bool_first = 0;
  static int	bool_mid = 0;

  mk_clear();
  display_allum(*allum);
  my_putstr("La maitre des Ténêbres réfléchit à sa tactique\n");
  usleep(2000000);
  if (bool_first == 0)
    {
      bool_first = 1;
      *allum -= 3;
    }
  else if (bool_mid < 3)
    {
      *allum -= analyse_choice(choice);
      bool_mid++;
    }
  else
    *allum -= final_choice(*allum);
  if (boyard_end("Le maitre des Ténêbres", *allum) == 0)
    return (0);
  return (1);
}

/*
** ia_boyard.c for allum in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 18:08:29 2015 Antoine Zanardi
** Last update Tue Feb 10 14:55:57 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	"my.h"
#include	"allum1.h"

int		ia_choose_low(int choice)
{
  if (choice == 3)
    return (2);
  else if (choice == 2)
    return (1);
  else if (choice == 1)
    return (3);
  return (1);
}

int		ia_choose_good(unsigned int *allum)
{
  if (*allum == 8)
    return (2);
  else if (*allum == 7)
    return (2);
  else if (*allum == 6)
    return (1);
  else if (*allum == 5)
    return (2);
  else if (*allum == 4)
    return (3);
  else if (*allum == 3)
    return (2);
  else if (*allum == 2)
    return (1);
  return (1);
}

void		ia_boyard(unsigned int *allum, int choice)
{
  mk_clear();
  display_allum(*allum);
  my_putstr("La maitre des Ténêbres réfléchit à sa tactique\n");
  usleep(2000000);
  if (*allum > 8)
    *allum -= ia_choose_low(choice);
  else if (*allum <= 8)
    *allum -= ia_choose_good(allum);
  if (boyard_end("Le maitre des Ténêbres", *allum) == 0)
    return;
}

void		player_boyard(unsigned int *allum, int *choice)
{
  mk_clear();
  display_allum(*allum);
  player_choice(allum, choice);
}

/*
** error.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 10:07:56 2015 Antoine Zanardi
** Last update Tue Feb 10 19:21:20 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"

void		my_putstr_error(int error)
{
  if (error == 1)
    my_putstr("Please choose a minimum of 3 rows for the game\n");
  exit(1);
}

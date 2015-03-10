/*
** fc_boyard.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 17:12:27 2015 Antoine Zanardi
** Last update Mon Feb  9 17:20:57 2015 Antoine Zanardi
*/

#include	"allum1.h"
#include	"my.h"

int		str_is_ot(char *str, int allum)
{
  int		nombre;

  nombre = my_getnbr(str);
  if (nombre == 0)
    {
      my_putstr("Vous devez choisir au minimum 1 allumette\n");
      return (1);
    }
  if (nombre >= 4)
    {
      my_putstr("Vous ne pouvez prendre que 3 allumettes à la fois\n");
      return (1);
    }
  if (allum - nombre < 1)
    {
      my_putstr("Il ne doit rester qu'une allumette pour gagner\n\n");
      return (1);
    }
  return (0);
}

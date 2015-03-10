/*
** alum1.h for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 09:35:18 2015 Antoine Zanardi
** Last update Tue Feb 10 18:50:03 2015 Antoine Zanardi
*/

#ifndef		ALLUM_H_
# define	ALUMM_H_

typedef struct	s_list
{
  unsigned int	nombre;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef	struct	s_param
{
  int		multiplayer;
  int		difficulty;
  int		mode;
}		t_param;

typedef	struct	s_choice
{
  int		row;
  int		number;
}		t_choice;

void		my_show_list(t_list *);
void		my_putstr_error(int);
void		fill_my_list(t_list **, int);
void		play_the_game(t_list **, int *, int);
void		change_line(t_list **, t_choice *, int *);
void		remove_elem_list(t_list **, int);
void		ia_boyard(unsigned int *, int);
void		game_boyard(int);
void		display_allum(unsigned int);
void		player_boyard(unsigned int *, int *);
void		player_choice(unsigned int*, int *);
void		game_multi(t_list **, int *);
void		bigger_row(t_list **, t_choice *);
int		bigger_line(t_list **);
int		boyard_end(char *, int);
int		ia_exp_boyard(unsigned int *, int);
int		str_is_ot(char *, int);
int		hard_ia(t_list **, int *);
int		easy_ia(t_list **, int *);
int		end_game(t_list *, char *);
int		mk_clear();
int		compare_a(char *, int, t_list *);
int		compare_nb(char *, int);
int		str_is_posi(char *);
int		add_top_list(t_list **, unsigned int);
int		add_bot_list(t_list **, unsigned int);
int		str_is_mode(char *);

#endif		/* !ALLUM_H_ */

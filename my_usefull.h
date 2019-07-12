/*
** my_usefull.h for my_usefull in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Feb 20 12:30:29 2017 Kevin Bidet
** Last update Sun Feb 26 15:56:49 2017 Kevin Bidet
*/

#ifndef MY_USEFULL_H_
# define MY_USEFULL_H_

#include <stdlib.h>
#include <unistd.h>

#define	READ_SIZE	4
#define BUF_SIZE	5
#define LAST_LINE	-200
#define FAILURE		84
#define SUCCESS		0
#define IA		1
#define PLAYER		2

typedef struct		s_tab_variables
{
  int			*tab;
  int			nb_stick;
  int			line;
  int			stick_max;
  int			column;
}			t_tab_var;

typedef struct		s_choice_game
{
  int			line;
  int			stick;
  char			*buf;
}			t_choice_game;

void			my_putnbr(int nb);
void			my_puterr(char c);
void			my_putchar(char c);
void			my_putstr(char *str);
void			my_errstr(char *str);
void			display_star_line(int column);
void			display_result(t_tab_var *tab);
void			display_my_board(t_tab_var *tab);
void			display_ia_turn(int line, int stick);
void			print_turn_info(t_choice_game *user);
void			create_int_tab(t_tab_var *tab, int line);
void			remove_stick(t_tab_var *tab);
int			my_getnbr(char *str);
int			ia_turn(t_tab_var *tab);
int			user_turn(t_tab_var *tab);
int			game_loop(t_tab_var *tab);
int			check_nb_argument(int ac);
int			check_number_line(char **av);
int			check_error(int ac, char **av);
int			check_false_input(char *input);
int			display_sticks(t_tab_var *tab, int j);
int			check_number_stick_removed(char **av);
int			check_too_much_stick(int input, int max);
int			check_nature_argument(int ac, char **av);
int			find_line(t_tab_var *tab, int stick_max);
int			check_user_line(char *input, t_tab_var *tab);
int			line_user(t_choice_game *user, t_tab_var *tab);
int			check_end(int *tab, int size, int last_player);
int			stick_user(t_choice_game *user, t_tab_var *tab);
int			check_stick_remain(int match_on_line, int input);
int			how_many_stick(t_tab_var *tab, int max, int line);
int			set_my_int_tab(t_tab_var *tab, int line, int stick);
int			check_user_stick(char *input, t_tab_var *tab,
					 t_choice_game *user);

#endif /* !MY_USEFULL_H_ */

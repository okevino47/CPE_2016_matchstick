/*
** display_input.c for display_input in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Tue Feb 21 17:48:39 2017 Kevin Bidet
** Last update Sun Feb 26 16:20:01 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	user_turn(t_tab_var *tab)
{
  t_choice_game	user;

  if ((user.buf = malloc(sizeof(char*) * BUF_SIZE)) == NULL)
    {
      my_errstr("Error while memory attribution of user input\n");
      return (FAILURE);
    }
  my_putstr("\nYour turn:\n");
  if (line_user(&user, tab) == FAILURE)
    return (FAILURE);
  if (stick_user(&user, tab) == FAILURE)
    return (FAILURE);
  print_turn_info(&user);
  if ((tab->tab[user.line - 1]) < 0)
    tab->tab[user.line] = tab->tab[user.line] - user.stick;
  else
    tab->tab[user.line - 1] = tab->tab[user.line - 1] - user.stick;
  return (SUCCESS);
}

int	game_loop(t_tab_var *tab)
{
  int	end;

  end = 0;
  if (user_turn(tab) == FAILURE)
    return (FAILURE);
  display_result(tab);
  if ((end = check_end(tab->tab, tab->line, 2)) == PLAYER)
    {
      my_putstr("You lost, too bad...\n");
      return (SUCCESS);
    }
  if (ia_turn(tab) == FAILURE)
    return (FAILURE);
  display_result(tab);
  if ((end = check_end(tab->tab, tab->line, 1)) == IA)
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (SUCCESS);
    }
  return (game_loop(tab));
}

int	check_end(int *tab, int size, int last_player)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (tab[i] > 0)
	return (0);
      i += 1;
    }
  if (last_player == PLAYER)
    return (PLAYER);
  else if (last_player == IA)
    return (IA);
  else
    return (0);
}

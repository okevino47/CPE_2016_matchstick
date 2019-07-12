/*
** main.c for main in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Feb 20 11:16:55 2017 Kevin Bidet
** Last update Sun Feb 26 16:31:17 2017 Kevin Bidet
*/

#include "my_usefull.h"
#include <stdio.h>	// à tej a la fin

int	main(int ac, char **av)
{
  t_tab_var	int_tab;
  int		winner;

  if (check_error(ac, av) == FAILURE)
    return (FAILURE);
  if ((set_my_int_tab(&int_tab, my_getnbr(av[1]),
		      my_getnbr(av[2]))) == FAILURE)
    return (FAILURE);
  create_int_tab(&int_tab, my_getnbr(av[1]));
  display_result(&int_tab);
  if ((winner = game_loop(&int_tab)) == FAILURE)
    return (FAILURE);
  return (winner);
}

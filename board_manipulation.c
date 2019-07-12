/*
** board_manipulation.c for board_manipulation in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Feb 20 15:09:34 2017 Kevin Bidet
** Last update Sat Feb 25 18:19:10 2017 Kevin Bidet
*/

#include "my_usefull.h"

void	create_int_tab(t_tab_var *tab, int line)
{
  int	i;

  i = 0;
  while (i < line)
    {
      tab->tab[i] = tab->nb_stick;
      tab->nb_stick += 2;
      i += 1;
    }
}

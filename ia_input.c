/*
** ia_input.c for ia_input in /media/bibibrutal/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/bibibrutal/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Sat Feb 25 13:43:11 2017 Kevin Bidet
** Last update Sun Feb 26 15:00:18 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	ia_turn(t_tab_var *tab)
{
  remove_stick(tab);
  return (SUCCESS);
}

void	remove_stick(t_tab_var *tab)
{
  int	stick_max;
  int	stick;
  int	line;

  stick_max = tab->stick_max;
  line = find_line(tab, stick_max);
  stick = how_many_stick(tab, stick_max, line);
  if (stick_max % stick == 1)
    {
      if (stick - 1 == 0)
	stick = 1;
      else
	stick -= 1;
    }
  tab->tab[line - 1] = tab->tab[line - 1] - stick;
  display_ia_turn(line, stick);
}

int	how_many_stick(t_tab_var *tab, int max, int line)
{
  int	i;

  i = 0;
  while ((i < max) && (i < (tab->tab[line - 1])))
    i += 1;
  return (i);
}

int	find_line(t_tab_var *tab, int stick_max)
{
  int	i;

  i = 0;
  while ((tab->tab[i] < stick_max) && (i < tab->line))
    i += 1;
  if (tab->tab[i] >= stick_max)
    return (i + 1);
  else if (stick_max == 1)
    return (1);
  else
    return (find_line(tab, (stick_max - 1)));
}

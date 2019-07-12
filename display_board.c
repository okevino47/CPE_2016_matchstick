/*
** display.c for display in /media/bibibrutal/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/bibibrutal/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Feb 20 15:48:16 2017 Kevin Bidet
** Last update Sun Feb 26 12:19:12 2017 Kevin Bidet
*/

#include "my_usefull.h"

void	display_result(t_tab_var *tab)
{
  display_star_line(tab->column);
  display_my_board(tab);
  display_star_line(tab->column);
}

int	display_sticks(t_tab_var *tab, int j)
{
  int	i;

  i = 0;
  while (i < tab->tab[j])
    {
      my_putchar('|');
      i += 1;
    }
  return (i);
}

void	display_my_board(t_tab_var *tab)
{
  int	i;
  int	j;
  int	space;

  j = 0;
  while (tab->tab[j] > LAST_LINE)
    {
      i = 0;
      my_putchar('*');
      while (i < (space = (tab->line) - j - 1))
	{
	  my_putchar(' ');
	  i += 1;
	}
      i = i + display_sticks(tab, j);
      while (i < (tab->column - 1))
	{
	  my_putchar(' ');
	  i += 1;
	}
      my_putstr("*\n");
      j += 1;
    }
}

void	display_star_line(int column)
{
  int	i;

  i = 0;
  while (i <= column)
    {
      my_putchar('*');
      i += 1;
    }
  my_putchar('\n');
}

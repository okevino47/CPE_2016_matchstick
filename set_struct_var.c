/*
** set_struct_var.c for set_struct_var in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Feb 20 13:23:47 2017 Kevin Bidet
** Last update Sat Feb 25 11:30:47 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	set_my_int_tab(t_tab_var *tab, int line, int stick)
{
  if ((tab->tab = malloc(sizeof(int) * ((line) + 1))) == NULL)
    {
      my_errstr("Error while memory atribution of int tab\n");
      return (FAILURE);
    }
  tab->tab[line] = LAST_LINE;
  tab->nb_stick = 1;
  tab->stick_max = stick;
  tab->line = line;
  tab->column = line * 2;
  return (SUCCESS);
}

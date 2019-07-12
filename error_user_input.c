/*
** error_user_input.c for error_user_input in /media/bibibrutal/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/bibibrutal/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Thu Feb 23 15:11:56 2017 Kevin Bidet
** Last update Sun Feb 26 16:31:05 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	check_user_line(char *input, t_tab_var *tab)
{
  int	i;

  i = 0;
  if (input[0] == '\0')
    {
      my_errstr("Error: invalid input (positive number expected)\n");
      return (FAILURE);
    }
  while (input[i] != '\0')
    {
      if ((input[i] < '0' || input[i] > '9') || (input[0] == '\n'))
	{
	  my_errstr("Error: invalid input (positive number expected)\n");
	  return (FAILURE);
	}
      else if ((input[0] <= '0') || (my_getnbr(input) > tab->line))
	{
	  my_putstr("Error: this line is out of range\n");
	  return (FAILURE);
	}
      i += 1;
    }
  return (SUCCESS);
}

int	check_user_stick(char *input, t_tab_var *tab, t_choice_game *user)
{
  if (input[0] == '\0')
    {
      my_errstr("Error: invalid input (positive number expected)\n");
      return (FAILURE);
    }
  if (check_false_input(input) == FAILURE)
    return (FAILURE);
  if ((check_too_much_stick(my_getnbr(input), tab->stick_max) == FAILURE)
      || (check_stick_remain((tab->tab[user->line - 1]),
			     my_getnbr(input))== FAILURE))
    return (FAILURE);
  else if (input[0] <= '0')
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_false_input(char *input)
{
  int	index;

  index = 0;
  if ((input[index] < '0' || input[index] > '9') || (input[index] == '\n'))
    {
      my_errstr("Error : invalid input (positive number expected)\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_too_much_stick(int input, int max)
{
  if (input > max)
    {
      my_putstr("Error: you cannot remove more than ");
      my_putnbr(max);
      my_putstr(" match(es) per turn\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_stick_remain(int match_on_line, int input)
{
  if (match_on_line < input)
    {
      my_putstr("Error: not enought matches on this line\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

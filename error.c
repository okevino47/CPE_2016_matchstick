/*
** error.c for error in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Tue Feb 21 17:13:41 2017 Kevin Bidet
** Last update Sat Feb 25 11:19:20 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	check_error(int ac, char **av)
{
  if (check_nb_argument(ac) == FAILURE)
    return (FAILURE);
  if (check_nature_argument(ac, av) == FAILURE)
    return (FAILURE);
  if (check_number_line(av) == FAILURE)
    return (FAILURE);
  if (check_number_stick_removed(av) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}

int	check_nb_argument(int ac)
{
  if (ac != 3)
    {
      my_errstr("Error: please check the argument number (line and stick)\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_number_line(char **av)
{
  if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 100)
    {
      my_errstr("Error: lines must be a positive number between 1 and 100\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_number_stick_removed(char **av)
{
  if (my_getnbr(av[2]) < 1)
    {
      my_errstr("Error: match(es) must be a valid number upper than 0\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_nature_argument(int ac, char **av)
{
  int	i;
  int	j;

  i = 1;
  while (i < ac)
    {
      j = 0;
      while (av[i][j] != '\0')
	{
	  if (av[i][j] < '0' || av[i][j] > '9')
	    {
	      my_errstr("Error: invalid input (positive number expected)\n");
	      return (FAILURE);
	    }
	  j += 1;
	}
      i += 1;
    }
  return (SUCCESS);
}

/*
** display_input.c for user_input in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Thu Feb 23 15:47:04 2017 Kevin Bidet
** Last update Sun Feb 26 16:14:12 2017 Kevin Bidet
*/

#include "my_usefull.h"

int	line_user(t_choice_game *user, t_tab_var *tab)
{
  my_putstr("line: ");
  if ((user->line = read(0, user->buf, READ_SIZE)) <= 0)
    {
      my_errstr("Error while user line choice reading\n");
      return (FAILURE);
    }
  user->buf[user->line - 1] = '\0';
  while (check_user_line(user->buf, tab) == FAILURE)
    user->line = line_user(user, tab);
  user->line = my_getnbr(user->buf);
  if ((user->line - 1) <= 0)
    return (0);
  return (user->line - 1);
}

int	stick_user(t_choice_game *user, t_tab_var *tab)
{
  my_putstr("Matches: ");
  if ((user->stick = read(0, user->buf, READ_SIZE)) <= 0)
    {
      my_errstr("Error while user match(es) choice reading\n");
      return (FAILURE);
    }
  user->buf[user->stick - 1] = '\0';
  while (check_user_stick(user->buf, tab, user) == FAILURE)
    {
      line_user(user, tab);
      stick_user(user, tab);
    }
  user->stick = my_getnbr(user->buf);
  if (user->stick == 0)
    return (user->stick);
  else if ((user->stick - 1) < 0)
    return (FAILURE);
  return (user->stick - 1);
}

void	print_turn_info(t_choice_game *user)
{
  my_putstr("Player removed ");
  my_putnbr(user->stick);
  my_putstr(" match(es) from line ");
  my_putnbr(user->line);
  my_putchar('\n');
}

void	display_ia_turn(int line, int stick)
{
  my_putstr("\nAI's turn...\nAI removed ");
  my_putnbr(stick);
  my_putstr(" match(es) from line ");
  my_putnbr(line);
  my_putchar('\n');
}

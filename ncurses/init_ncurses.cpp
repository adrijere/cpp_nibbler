//
// init_ncurses.cpp for init_ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:19:11 2015 simon hure
// Last update Mon Mar 30 14:56:22 2015 simon hure
//

#include	"ncurses.hh"

extern "C" IDisplay* create_t(int const &x, int const &y) // get param from dlsym part
{
  return (new Ncurses(int x, int y));
}

Ncurses::Ncurses(int x, int y)
{
  int	x = 60; //tmp for testing
  int	y = 50; //tmp

  initscr();
  noecho();
  curs_set(FALSE);
  x += 2;
  y += 2;

  WINDOW *game = newwin(y, x, 0, 0);

  draw_border(game);
  
  handle_resize(stdscr, game, x, y);

  wrefresh(game);

  _game = game;
  _x = x;
  _y = y;

  // sleep(6);

  // delwin(game);

  // endwin();
}

void	Ncurses::handle_resize(WINDOW *std, WINDOW *game ,int x, int y)
{
  int	new_x;
  int	new_y;

  getmaxyx(std, new_y, new_x);
  if (new_y < y || new_x < x)
    {
      wclear(std);
      wclear(game);
      mvwprintw(game, 0, 0,"Error Windows Too Small");
    }
}

t_move	Ncurses::move()
{
  int	in;

  in = getch();
  switch (in)
    {
    case up_key:
      return (UP);
    case down_key:
      return (DOWN);
    case left_key:
      return (LEFT);
    case right_key:
      return (RIGHT);
    case esc_key:
      {
	std::cout << "EXIT" << std::endl;
	break;
      }
    }
}

void	Ncurses::display(std::list<t_snake> snake, const t_food food)
{

}

void	Ncurses::draw_border(WINDOW *screen)
{
  int	x, y, i;

  i = 0;
  getmaxyx(screen, y, x);
  while (i < x)
    {
      if (i >= x/2 - 4 && i <= x/2)
	i++;
      mvwprintw(screen, 0, i, "-");
      i++;
    }
  i = 0;
  while (i < x)
    {
      mvwprintw(screen, y - 1, i, "-");
      i++;
    }
  i = 0;
  while (i < y)
    {
      mvwprintw(screen, i, 0, "|");
      i++;
    }
  i = 0;
  while (i < y)
    {
      mvwprintw(screen, i, x - 1, "|");
      i++;
    }
  mvwprintw(screen, 0, x/2 - 4,"Nibbler");
}

//
// init_ncurses.cpp for init_ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:19:11 2015 simon hure
// Last update Wed Apr  1 17:40:31 2015 simon hure
//

#include	"ncurses.hh"

extern "C" IDisplay *create_t(int const &x, int const &y)
{
  (void) x;
  (void) y;
  return (new Ncurses(x, y));
}

Ncurses::~Ncurses()
{

}

Ncurses::Ncurses(int x, int y)
{
  initscr();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  x += 2;
  y += 2;
  _game = newwin(y, x, 0, 0);
  draw_border(_game);
  handle_resize(stdscr, _game, x, y);
  wrefresh(_game);
  _x = x;
  _y = y;

  //sleep(1);
  // delwin(game);
  // endwin();
}

void	Ncurses::win_quit()
{
  wclear(_game);
  delwin(_game);
  endwin();
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

void	Ncurses::refresh()
{

}

t_move	Ncurses::move()
{
  int	in;
  int	sleep;

  sleep = 0;
  in = 0;
  while (sleep < 100000000)
    sleep++;
  in = getch();
  switch (in)
    {
    case KEY_UP:
      return (UP);
    case KEY_DOWN:
      return (DOWN);
    case KEY_LEFT:
      return (LEFT);
    case KEY_RIGHT:
      return (RIGHT);
    case esc_key:
      {
	return (ESC);
	// delwin(_game);
	// endwin();
	// std::cout << in << " EXIT" << std::endl;
	// exit(0);
	// break;
      }
    }
  return NONE;
}

void	Ncurses::snake_body(t_snake m)
{
  mvwprintw(_game, m.y, m.x, "*");
  wrefresh(_game);
}

void	Ncurses::display(std::list<t_snake> snake, const t_food food)
{
  wclear(_game);
  draw_border(_game);
  for_each(snake.begin(), snake.end(), bind1st(std::mem_fun(&Ncurses::snake_body), this));
  mvwprintw(_game, food.y, food.x, "@");
  wrefresh(_game);
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

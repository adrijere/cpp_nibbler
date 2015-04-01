//
// init_ncurses.cpp for init_ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:19:11 2015 simon hure
// Last update Wed Apr  1 13:27:11 2015 simon hure
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
  // initscr();
  // curs_set(FALSE);
  // keypad(stdscr, TRUE);
  // noecho();
  // nodelay(stdscr, TRUE);
  // x += 2;
  // y += 2;
  // WINDOW *game = newwin(y, x, 0, 0);
  // draw_border(game);
  // handle_resize(stdscr, game, x, y);
  // wrefresh(game);
  // _game = game;
  // _x = x;
  // _y = y;
  // sleep(2);

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
  std::cout << "input " << in << std::endl;
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
	delwin(_game);
	endwin();
	std::cout << in << " EXIT" << std::endl;
	break;
      }
    }
  return NONE;
}

void	Ncurses::snake_body(t_snake m)
{
  std::cout << "-*>X = " << m.x << " -*>Y = " << m.y << std::endl;
  mvwprintw(_game, m.y, m.x, "*");
}

void	Ncurses::display(std::list<t_snake> snake, const t_food food)
{
  for_each(snake.begin(), snake.end(), bind1st(std::mem_fun(&Ncurses::snake_body), this));
  std::cout << "FOODX = " << food.x << " FOODY = " << food.y << std::endl;
  mvwprintw(_game, food.y, food.x, "@");
  draw_border(_game);
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

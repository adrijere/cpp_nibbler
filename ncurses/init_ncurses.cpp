//
// init_ncurses.cpp for init_ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:19:11 2015 simon hure
// Last update Thu Apr  2 15:40:53 2015 simon hure
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
  start_color();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  x += 2;
  y += 2;
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_BLUE, COLOR_BLACK);
  init_pair(7, COLOR_BLACK, COLOR_GREEN);
  _game = newwin(y, x, 0, 0);
  draw_border();
  handle_resize();
  wrefresh(_game);
  _x = x;
  _y = y;
}

void	Ncurses::win_quit()
{
  wclear(_game);
  delwin(_game);
  endwin();
}

void	Ncurses::handle_resize()
{
  wclear(_game);
  mvwprintw(_game, 0, 0,"Error Windows Too Small");
}

t_move	Ncurses::move()
{
  int	in;

  in = 0;
  usleep(150000);
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
      return (ESC);
    }
  return NONE;
}

void	Ncurses::snake_body(t_snake const m)
{
  wattron(_game, COLOR_PAIR(2));
  mvwprintw(_game, m.y + 1, m.x + 1, "*");
  wattroff(_game, COLOR_PAIR(2));
}

void	Ncurses::snake_head(int const &x, int const &y)
{
  wattron(_game, COLOR_PAIR(3));
  mvwprintw(_game, y + 1, x + 1, "0");
  wattroff(_game, COLOR_PAIR(3));
}

void	Ncurses::display(std::list<t_snake> snake, const t_food food)
{
  wclear(_game);
  draw_border();
  for_each(snake.begin(), snake.end(), bind1st(std::mem_fun(&Ncurses::snake_body), this));
  snake_head(snake.begin()->x, snake.begin()->y);
  wattron(_game, COLOR_PAIR(1));
  mvwprintw(_game, food.y + 1, food.x + 1, "@");
  wattroff(_game, COLOR_PAIR(1));
  wrefresh(_game);
}

void	Ncurses::draw_border()
{
  int	x, y, i;

  i = 0;
  getmaxyx(_game, y, x);
  wattron(_game, COLOR_PAIR(7));
  while (i < x)
    {
      if (i >= x/2 - 4 && i <= x/2)
	i++;
      mvwprintw(_game, 0, i, "-");
      i++;
    }
  i = 0;
  while (i < x)
    {
      mvwprintw(_game, y - 1, i, "-");
      i++;
    }
  i = 0;
  while (i < y)
    {
      mvwprintw(_game, i, 0, "|");
      i++;
    }
  i = 0;
  while (i < y)
    {
      mvwprintw(_game, i, x - 1, "|");
      i++;
    }
  wattroff(_game, COLOR_PAIR(7));
  wattron(_game, COLOR_PAIR(6));
  mvwprintw(_game, 0, x/2 - 4, "N");
  wattroff(_game, COLOR_PAIR(6));
  wattron(_game, COLOR_PAIR(6));
  mvwprintw(_game, 0, x/2 - 3, "i");
  wattroff(_game, COLOR_PAIR(6));
  mvwprintw(_game, 0, x/2 - 2, "b");
  mvwprintw(_game, 0, x/2 - 1, "b");
  mvwprintw(_game, 0, x/2 - 0, "l");
  wattron(_game, COLOR_PAIR(1));
  mvwprintw(_game, 0, x/2 + 1, "e");
  wattroff(_game, COLOR_PAIR(1));
  wattron(_game, COLOR_PAIR(1));
  mvwprintw(_game, 0, x/2 + 2, "r");
  wattroff(_game, COLOR_PAIR(1));
}

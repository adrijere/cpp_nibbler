/*
** Snake.cpp for Snake in /home/mathon_j/rendu/cpp_nibbler/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:39:29 2015 Jérémy MATHON
** Last update Tue Mar 24 09:18:51 2015 Jérémy MATHON
*/

#include	"Snake.hpp"

Snake::Snake(int const &w, int const &h) : width(w), height(h)
{
  this->snake.push_front((w % 2) - 2, h % 2);
  this->snake.push_front((w % 2) - 1, h % 2);
  this->snake.push_front(w % 2), h % 2);
  this->snake.push_front((w % 2) + 1, h % 2);
}

const	std::list<t_snake>	Snake::&get_snake() const
{
  return (this->snake);
}

const	t_food			Snake::&get_food() const
{
  return (this->_food);
}

void				Snake::init_food(int const &x, int const &y)
{
  std::list<t_snake>::iterator	it;

  this->_food.x = rand() % x;
  this->_food.y = rand() % y;
  for (it = this->snake.begin(); it != this->snake.end(); ++it)
    {
      if (it.x == this->_food.x && it.y == this->_food.y)
	this->init_food(x, y);
    }
}

void				Snake::check_food(int const &x, int const &y)
{
  if (this->get_snake().front().x == this->get_food().x && this->get_snake().front().x == this->get_food().y)
    {
      this->init_food(x, y);
      this->snake.push_front(x, y);
    }
  else
    {
      this->snake.push_front(x, y);
      this->snake.pop_back();
    }
}

int				Snake::check_eat(int const &x, int const &y)
{
  std::list<t_snake>::iterator	it;

  if (this->snake.front().x < 0 || this->snake.front().y < 0 || this->snake.front().x >= x || this->snake.front().y >=y)
    return (-1);
  for (it = this->snake.begin(); it != this->snake.end(); ++it)
    {
      if (it != this->snake.begin() && this->snake.front().x == it->x && this->snake.front().y == it->y)
	return (-1);
    }
  return (0);
}

int				loop_game(int const &x, int const &y, IDisplay *Window)
{
  Snake				snake(x, y);
  t_snake			tmp;

  snake.init_apple(x, y);
  while (42)
    {
      tmp.move = Window->move();
      tmp.x = snake.get_snake().front().x;
      tmp.y = snake.get_snake().front().y;
      if (tmp.move == LEFT)
	tmp.x--;
      else if (tmp.move == RIGHT)
	tmp.x++;
      else if (tmp.move == UP)
	tmp.y--;
      else if (tmp.move == DOWN)
	tmp.y++;
      if (snake.check_eat(x, y) == -1)
	{
	  std::cout << "score : " << python.get_snake().size() - 4 << std::endl;
	  return (-1);
	}
      snake.check_food(x, y, tmp);
      Window->display_snake(snake.get_snake(), snake.get_food());
    }
}

int				check_arg(int const &x, int const &y, const std::string &lib)
{
  if (x < 10 || x > 40)
    {
      std::cerr << "Error : width must be between 10 and 40." << std::endl;
      return (1);
    }
  else if (y < 10 || y > 40)
    {
      std::cerr << "Error : height must be between 10 and 40." << std::endl;
      return (1);
    }
  else if (lib != "lib_nibbler_sdl.so" && lib != "lib_nibbler_ncurses.so" && lib != "lib_nibbler_opengl.so")
    {
      std::cerr << "Error : library must be :\nlib_nibbler_sdl.so\nlib_nibbler_ncurses.so\nlib_nibbler_opengl.so" << std::endl;
      return (1);
    }
  return (0);
}

int				main(int ac, char **av)
{
  int				width;
  int				height;
  std::istringstream		buffer(av[1]);
  std::istringstream		buffer2(av[2]);

  if (ac != 4)
    {
      std::cerr << "Usage : ./nibbler <width> <height> <graphic library>" << std::endl;
      return (1);
    }
  buffer >> width;
  buffer2 >> height;
  if ((check_arg(width, height, av[3])) == 1)
    return (1);
  srand(time(NULL));
  load_library(width, height, av[3]);
  return (0);
}

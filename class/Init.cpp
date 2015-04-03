//
// Init.cpp for init in /home/hure_s/tek2/rendu/cpp_nibbler/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Tue Mar 24 12:55:23 2015 simon hure
// Last update Fri Apr  3 16:46:44 2015 simon hure

#include "../header/Init.hh"

Init::Init()
{

}

int		Init::loop_game(int const &x, int const &y, IDisplay *Window)
{
  Snake		snake(x, y);
  t_snake	tmp;
  bool		loop = true;
  e_move	dir;

  dir = RIGHT;
  snake.init_food(x, y);
  while (loop == true)
    {
      Window->display(snake.get_snake(), snake.get_food());
      tmp.move = Window->move();
      if (tmp.move != NONE)
	dir = tmp.move;
      tmp.x = snake.get_snake().front().x;
      tmp.y = snake.get_snake().front().y;
      if (tmp.move == ESC)
	{
	  Window->win_quit();
	  loop = false;
	}
      if (snake.check_eat(x, y, tmp) == -1)
        {
	  Window->win_quit();
	  std::cout << "score : " << snake.get_snake().size() - 4 << std::endl;
          return (-1);
        }
      snake.check_food(x, y, tmp, dir);
    }
  return (0);
}

int	Init::check_arg(int const &x, int const &y, const std::string &lib)
{
  try 
    {
      if (x < 10 || x > 80)
	throw(ArgumentException("width must be between 10 and 80"));
      else if (y < 10 || y > 80)
	throw(ArgumentException("height must be between 10 and 80"));
      else if (lib != "lib_nibbler_sdl.so" && lib != "lib_nibbler_ncurses.so" && lib != "lib_nibbler_\
xlib.so")
	throw(ArgumentException("Wrong library name.\nLibrary must be :\nlib_nibbler_sdl.so\nlib_nibbler_ncurses.so\nlib_ni\
bbler_xlib.so"));
    }
  catch (const Exception e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}

int	Init::start(int ac, char **av)
{
  int                           width;
  int                           height;

try
  {
    if (ac != 4)
      throw(ArgumentException("Usage : ./nibbler <width> <height> <graphic library>"));
  }
 catch (const Exception e)
   {
     std::cerr << e.what() << std::endl;
   }
  std::istringstream            buffer(av[1]);
  std::istringstream            buffer2(av[2]);

  buffer >> width;
  buffer2 >> height;
  check_arg(width, height, av[3]);
  load_library(width, height, av[3]);
  return (0);
}

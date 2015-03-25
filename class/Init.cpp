//
// Init.cpp for init in /home/hure_s/tek2/rendu/cpp_nibbler/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Tue Mar 24 12:55:23 2015 simon hure
// Last update Wed Mar 25 11:55:04 2015 Valentin Cardon

#include "../header/Init.hh"

Init::Init()
{

}

int		Init::loop_game(int const &x, int const &y, IDisplay *Window)
{
  Snake		snake(x, y);
  t_snake	tmp;

  //snake.init_apple(x, y);
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
	  std::cout << "score : " << snake.get_snake().size() - 4 << std::endl;
          return (-1);
        }
      snake.check_food(x, y);
      //Window->display_snake(snake.get_snake(), snake.get_food());
    }
}

int	Init::check_arg(int const &x, int const &y, const std::string &lib)
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
  else if (lib != "lib_nibbler_sdl.so" && lib != "lib_nibbler_ncurses.so" && lib != "lib_nibbler_\
opengl.so")
    {
      std::cerr << "Error : library must be :\nlib_nibbler_sdl.so\nlib_nibbler_ncurses.so\nlib_ni\
bbler_opengl.so" << std::endl;
      return (1);
    }
  return (0);
}

int	Init::start(int ac, char **av)
{
  int                           width;
  int                           height;

  if (ac != 4)
    {
      std::cerr << "Usage : ./nibbler <width> <height> <graphic library>" << std::endl;
      return (-1);
    }
  std::istringstream            buffer(av[1]);
  std::istringstream            buffer2(av[2]);

  buffer >> width;
  buffer2 >> height;
  if (check_arg(width, height, av[3]) == 1)
    return (-1);
  load_library(width, height, av[3]);
  //start_game loop;
  return (0);
}

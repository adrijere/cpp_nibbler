//
// init_sdl.cpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:36:54 2015 Valentin Cardon
// Last update Wed Apr  1 13:00:05 2015 Valentin Cardon
//

#include	"sdl.hpp"

extern	"C" IDisplay *create_t(int const &x, int const &y)
{
  (void)x;
  (void)y;
  return (new Sdl(x, y));
}

Sdl::Sdl(int x, int y)
{
  this->screen = NULL;
  this->x = x * 10;
  this->y = y * 10;
}

int	Sdl::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (0);
  if (this->x <= 0 || this->y <= 0)
    {
      std::cout << "Size too small" << std::endl;
      return (0);
    }
  SDL_WM_SetCaption("Nibbler", NULL);
  if ((this->screen = SDL_SetVideoMode(this->x, this->y, BPP, SDL_HWSURFACE))
      == NULL)
    return (0);
  return (1);
}

void		Sdl::display(std::list<t_snake> snake, const t_food food)
{
  init();
  (void)snake;
  (void)food;
  while(SDL_WaitEvent(&this->event))
    {
      this->touch = move();
      for_each(snake.begin(), snake.end(), print_snake);      
      std::cout << "move = " << this->touch << std::endl;
    }
}

void		Sdl::print_snake(t_snake elem)
{
  int		i;
  int		j;

  i = elem.x + 5;
  j = elem.y + 5;
  while (elem.x < i)
    {
      while (elem.y < j)
	{
	  
	  elem.y++;
	}
      elem.x++;
    }
}

t_move	Sdl::move()
{
  while (SDL_WaitEvent(&this->event))
    {
      if (event.key.keysym.sym == SDLK_UP)
	return (UP);
      if (event.key.keysym.sym == SDLK_DOWN)
	return (DOWN);
      if (event.key.keysym.sym == SDLK_LEFT)
	return (LEFT);
      if (event.key.keysym.sym == SDLK_RIGHT)
	return (RIGHT);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	SDL_Quit();
    }
  return (NONE);
}

  Sdl::~Sdl()
  {}

//
// init_sdl.cpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:36:54 2015 Valentin Cardon
// Last update Wed Apr  1 18:02:06 2015 Valentin Cardon
//

#include	"sdl.hpp"
#include	<unistd.h>

extern	"C" IDisplay *create_t(int const &x, int const &y)
{
  return (new Sdl(x, y));
}

Sdl::Sdl(int x, int y)
{

  this->x = x * 10;
  this->y = y * 10;
  this->screen = init();
}

SDL_Surface	*Sdl::init()
{
  SDL_Surface	*tmp;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (NULL);
  if (this->x <= 0 || this->y <= 0)
    {
      std::cout << "Size too small" << std::endl;
      return (NULL);
    }
  SDL_WM_SetCaption("Nibbler", NULL);
  if ((tmp = SDL_SetVideoMode(this->x, this->y, BPP, SDL_HWSURFACE))
      == NULL)
    return (NULL);
  return (tmp);
}

void		Sdl::display(std::list<t_snake> snake, const t_food food)
{
  std::list<t_snake>::iterator it;

  SDL_FillRect(this->screen, NULL, 0);
  for (it = snake.begin(); it != snake.end(); ++it)
    print_snake(*it);
  print_food(food);
  refresh();
}

void		Sdl::print_snake(t_snake elem)
{
  SDL_Surface	*square;
  SDL_Rect	rect;

  rect.x = elem.x * 10;
  rect.y = elem.y * 10;
  square = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 15, 32, 0, 0, 0, 0); 
  SDL_FillRect(square, NULL, SDL_MapRGB(this->screen->format, 0, 255, 0));
  SDL_BlitSurface(square, NULL, this->screen, &rect);
}

void		Sdl::print_food(t_food food)
{
  SDL_Surface	*square;
  SDL_Rect	rect;

  rect.x = food.x * 10;
  rect.y = food.y * 10;
  square = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 15, 32, 0, 0, 0, 0); 
  SDL_FillRect(square, NULL, SDL_MapRGB(this->screen->format, 255, 0, 0));
  SDL_BlitSurface(square, NULL, this->screen, &rect);
}

void		Sdl::refresh()
{
  SDL_Flip(this->screen);
}

e_move	Sdl::move()
{
  int		sleep = 0;

  SDL_PollEvent(&this->event);
  usleep(40000);
  switch (this->event.type)
    {
    case SDL_QUIT:
      return (ESC);
    case SDL_KEYDOWN:
      switch (this->event.key.keysym.sym)
	{
	case SDLK_LEFT:
	  return (LEFT);
	case SDLK_RIGHT:
	  return (RIGHT);
	case SDLK_DOWN:
	  return (DOWN);
	case SDLK_UP:
	  return (UP);
	}
    }
  return (NONE);
}
void	Sdl::win_quit()
{}

Sdl::~Sdl()
{}

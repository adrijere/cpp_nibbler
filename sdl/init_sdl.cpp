//
// init_sdl.cpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:36:54 2015 Valentin Cardon
// Last update Wed Mar 25 11:48:25 2015 Valentin Cardon
//

#include	"sdl.hpp"

create::create()
{
  this->screen = NULL;
}

int	create::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (0);
  SDL_WM_SetCaption("Nibbler", NULL);
  if ((screen = SDL_SetVideoMode(HEIGHT, WIDTH, BPP, SDL_HWSURFACE))
      == NULL)
    return (0);
  while (SDL_WaitEvent(&event))
    if (event.key.keysym.sym == SDLK_ESCAPE)
      {
	SDL_Quit();
	return (0);
      }
  return (0);
}

create::~create()
{}

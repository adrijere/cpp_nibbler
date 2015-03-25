//
// sdl.hpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:37:46 2015 Valentin Cardon
// Last update Wed Mar 25 11:41:33 2015 Valentin Cardon
//

#ifndef		_SDL_HPP_
#define		_SDL_HPP_

#define		HEIGHT	800
#define		WIDTH	800
#define		BPP	32

# include	<SDL/SDL.h>
# include	"../header/IDisplay.hpp"

class		create : public IDisplay
{
private:
  SDL_Surface	*screen;
  SDL_Event	event;

public:
  create();
  int	init();
  ~create();
};

#endif		/* _SDL_HPP_ */

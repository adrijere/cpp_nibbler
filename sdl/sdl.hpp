//
// sdl.hpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:37:46 2015 Valentin Cardon
// Last update Wed Apr  1 12:00:26 2015 Valentin Cardon
//

#ifndef		_SDL_HPP_
#define		_SDL_HPP_

#define		BPP	32

# include	<SDL/SDL.h>
# include	"../header/IDisplay.hpp"

class		Sdl : public IDisplay
{
private:
  SDL_Surface	*screen;
  SDL_Event	event;
  e_move	touch;
  int		x;
  int		y;


public:
  Sdl(int x, int y);
  void		display(std::list<t_snake>, const t_food);
  t_move	move();
  int		init();
  void		print_snake(std::list<t_snake>, SDL_Surface*);
  ~Sdl();
};

#endif		/* _SDL_HPP_ */

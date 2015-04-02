//
// sdl.hpp for nibbler in /home/cardon_v/Documents/CPP/cpp_nibbler/sdl
// 
// Made by Valentin Cardon
// Login   <cardon_v@epitech.net>
// 
// Started on  Tue Mar 24 11:37:46 2015 Valentin Cardon
// Last update Thu Apr  2 14:26:49 2015 Valentin Cardon
//

#ifndef		_SDL_HPP_
#define		_SDL_HPP_

#define		BPP	32

# include	<SDL/SDL.h>
# include	<iostream>
#include	<algorithm>
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
  e_move	move();
  SDL_Surface	*init();
  void		print_snake(t_snake);
  void		print_head(t_snake);
  void		print_food(t_food);
  void		refresh();
  void		win_quit();
  ~Sdl();
};

#endif		/* _SDL_HPP_ */

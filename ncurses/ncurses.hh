//
// ncurses.hh for ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:33:18 2015 simon hure
// Last update Mon Mar 30 14:55:46 2015 simon hure
//

#ifndef _NCURSES_HH_
#define _NCURSES_HH_

#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "../header/IDisplay.hpp"

class Ncurses
{
protected:
  WINDOW *_game;
  int	_x;
  int	_y;
public:
  Ncurses(int x, int y);
  void draw_border(WINDOW *screen);
  void handle_resize(WINDOW *std, WINDOW *game, int x, int y);
};

#endif

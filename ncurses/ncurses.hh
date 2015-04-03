//
// ncurses.hh for ncurses in /home/hure_s/tek2/rendu/cpp_nibbler/ncurses
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Mon Mar 30 11:33:18 2015 simon hure
// Last update Fri Apr  3 16:23:08 2015 simon hure
//

#ifndef _NCURSES_HH_
#define _NCURSES_HH_

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <ncurses.h>
#include <unistd.h>
#include "../header/Exception.hh"
#include "../header/IDisplay.hpp"

#define esc_key 27

class Ncurses : public IDisplay
{
protected:
  WINDOW *_game;
  int	_x;
  int	_y;
  int	_dtime;
public:
  Ncurses(int x, int y);
  ~Ncurses();
  void display(std::list<t_snake> snake, const t_food food);
  t_move move();
  void set_color_pair();
  void win_quit();
  int check_env();
  void speedup(int const &, int const &, int const &, int const &);
  void draw_border();
  void handle_resize();
  void snake_body(t_snake const m);
  void snake_head(int const &x, int const &y);
};

#endif

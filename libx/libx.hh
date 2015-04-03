//
// libx.hh for libx in /home/hure_s/tek2/rendu/cpp_nibbler/libx
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu Apr  2 10:18:27 2015 simon hure
// Last update Fri Apr  3 11:45:45 2015 simon hure
//

#ifndef	_LIBX_
#define _LIBX_

#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include "../header/IDisplay.hpp"

class Libx : public IDisplay
{
private:
  Display *_me;
  Window _win;
  int	_screen_num;
  XColor _xred;
  XColor _xyel;
  Colormap _cmap;
  GC _gc;
  int _x;
  int _y;
public:
  Libx(int const &, int const &);
  virtual ~Libx();
  void win_quit();
  int check_env(char **environ);
  void print_snake(t_snake const elem);
  t_move move();
  void display(std::list<t_snake> snake, const t_food food);
};

#endif

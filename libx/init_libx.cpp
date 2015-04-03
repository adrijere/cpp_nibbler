//
// init_libx.cpp for init_libx in /home/hure_s/tek2/rendu/cpp_nibbler/libx
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu Apr  2 10:16:31 2015 simon hure
// Last update Fri Apr  3 14:34:53 2015 simon hure
//

#include	"libx.hh"
#include <exception>
extern "C" IDisplay *create_t(int const &x, int const &y)
{
  (void) x;
  (void) y;
  return (new Libx(x, y));
}

Libx::Libx(int const &x, int const &y)
{
  int	newx, newy;

  newx = x * 20;
  newy = y * 20;
  if (check_env() == -1)
    {
      std::cerr << "Error : DISPLAY Environement variable needed!" << std::endl;
      exit (0);
    }
  _me = XOpenDisplay(NULL);
  _win = XCreateSimpleWindow(_me, RootWindow(_me, 0), 1, 1, newx, newy, 0, BlackPixel(_me, 0), BlackPixel(_me, 0));
  _screen_num = DefaultScreen(_me);
  XSelectInput(_me, _win, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask);
  XMapWindow(_me, _win);
  _gc = XCreateGC(_me, _win, 0, NULL);
  XStoreName(_me, _win, "Nibbler");
  _dtime = 200000;
  _cmap = DefaultColormap(_me, 0);
  XParseColor(_me, _cmap, "#990000", &_xred);
  XParseColor(_me, _cmap, "#E6E600", &_xyel);
  XAllocColor(_me, _cmap, &_xred);
  XAllocColor(_me, _cmap, &_xyel);
}

Libx::~Libx()
{

}

int	Libx::check_env()
{
  int	i;
  extern char **environ;
  std::string tmp;

  i = 0;
  while (environ[i])
    {
      tmp = environ[i];
      tmp = tmp.substr(0, tmp.find("="));
      if (tmp == "DISPLAY")
	return (0);
      i++;
    }
  return (-1);
}

void	Libx::win_quit()
{

}

t_move	Libx::move()
{
  XEvent	rep;
  
  usleep(_dtime);
  if (XCheckMaskEvent(_me, KeyPressMask ,&rep) == 0)
    {
      XFlush(_me);
      return (NONE);
    }
  switch (rep.type)
    {	  
    case KeyPress:
      if (XLookupKeysym(&rep.xkey, 0) == XK_Escape)
	return (ESC);
      else if (XLookupKeysym(&rep.xkey, 0) == XK_Up)
	return (UP);
      else if (XLookupKeysym(&rep.xkey, 0) == XK_Down)
	return (DOWN);
      else if (XLookupKeysym(&rep.xkey, 0) == XK_Left)
	return (LEFT);
      else if (XLookupKeysym(&rep.xkey, 0) == XK_Right)
	return (RIGHT);
      break;
    }
  return (NONE);
}

void	Libx::print_snake(t_snake const elem)
{
  XDrawRectangle(_me, _win, _gc, elem.x * 20, elem.y * 20, 10, 10);
  XFillRectangle(_me, _win, _gc, elem.x * 20, elem.y * 20, 10, 10);
}

void	Libx::speedup(int const &sn_x, int const &sn_y, int const &fo_x, int const &fo_y)
{
  if (sn_x == fo_x && sn_y == fo_y)
    {
      _dtime -= 10000;
      if (_dtime <= 0)
	_dtime = 10000;
    }
}

void	Libx::display(std::list<t_snake> snake, const t_food food)
{
  XClearWindow(_me, _win);
  XSetForeground(_me, _gc, WhitePixel(_me, _screen_num));
  XSetFillStyle(_me, _gc, FillSolid);
  for_each(snake.begin(), snake.end(), bind1st(std::mem_fun(&Libx::print_snake), this));
  XSetForeground(_me, _gc, _xyel.pixel);
  XSetFillStyle(_me, _gc, FillSolid);
  XDrawRectangle(_me, _win, _gc, snake.begin()->x * 20 , snake.begin()->y * 20, 10, 10);
  XFillRectangle(_me, _win, _gc, snake.begin()->x * 20 , snake.begin()->y * 20, 10, 10);
  XSetForeground(_me, _gc, _xred.pixel);
  XSetFillStyle(_me, _gc, FillSolid);
  XDrawRectangle(_me, _win, _gc, food.x * 20 , food.y * 20, 10, 10);
  XFillRectangle(_me, _win, _gc, food.x * 20 , food.y * 20, 10, 10);
  speedup(snake.begin()->x, snake.begin()->y, food.x, food.y);
  XFlush(_me);
}

//
// init_libx.cpp for init_libx in /home/hure_s/tek2/rendu/cpp_nibbler/libx
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Thu Apr  2 10:16:31 2015 simon hure
// Last update Fri Apr  3 18:57:01 2015 simon hure
//

#include	"libx.hh"

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
  try
    {
      if (check_env() == -1)
	throw (DisplayException("Environement variable needed"));
    }
  catch (const Exception e)
    {
      std::cerr << e.what() << std::endl;
    }
  _me = XOpenDisplay(NULL);
  _win = XCreateSimpleWindow(_me, RootWindow(_me, 0), 1, 1, newx, newy, 0, BlackPixel(_me, 0), BlackPixel(_me, 0));
  _screen_num = DefaultScreen(_me);
  XSelectInput(_me, _win, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask);
  XMapWindow(_me, _win);
  _gc = XCreateGC(_me, _win, 0, NULL);
  XStoreName(_me, _win, "Nibbler");
  _dtime = 200000;
  set_color_value();
  _x = newx + 40;
  _y = newy + 40;
  draw_border();
  Atom wmDelete=XInternAtom(_me, "WM_DELETE_WINDOW", True);
  XSetWMProtocols(_me, _win, &wmDelete, 1);
}

void	Libx::set_color_value()
{
  _cmap = DefaultColormap(_me, 0);
  XParseColor(_me, _cmap, "#990000", &_xred);
  XParseColor(_me, _cmap, "#007FFF", &_xblu);
  XParseColor(_me, _cmap, "#E6E600", &_xyel);
  XAllocColor(_me, _cmap, &_xred);
  XAllocColor(_me, _cmap, &_xblu);
  XAllocColor(_me, _cmap, &_xyel);
}

Libx::~Libx()
{

}

void	Libx::draw_border()
{
  XSetForeground(_me, _gc, _xblu.pixel);
  XSetFillStyle(_me, _gc, FillSolid);
}

int	Libx::check_env()
{
  int		i;
  extern char	**environ;
  std::string	tmp;

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
  if (XCheckMaskEvent(_me, KeyPressMask, &rep) == 0)
    {
      XFlush(_me);
      return (NONE);
    }
  switch (rep.type)
    {
    case KeyPress:
      switch (XLookupKeysym(&rep.xkey, 0))
	{
	case XK_Escape:
	  return (ESC);
	case XK_Up:
	  return (UP);
	case XK_Down:
	  return (DOWN);
	case XK_Left:
	  return (LEFT);
	case XK_Right:
	  return (RIGHT);
	}
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

void	Libx::print_head(int const &sn_x, int const &sn_y)
{
  XSetForeground(_me, _gc, _xyel.pixel);
  XSetFillStyle(_me, _gc, FillSolid);
  XDrawRectangle(_me, _win, _gc, sn_x , sn_y, 10, 10);
  XFillRectangle(_me, _win, _gc, sn_x , sn_y, 10, 10);
}

void	Libx::print_food(int const &food_x, int const &food_y)
{
  XSetForeground(_me, _gc, _xred.pixel);
  XSetFillStyle(_me, _gc, FillSolid);
  XDrawRectangle(_me, _win, _gc, food_x , food_y, 10, 10);
  XFillRectangle(_me, _win, _gc, food_x , food_y, 10, 10);
}

void	Libx::display(std::list<t_snake> snake, const t_food food)
{
  XClearWindow(_me, _win);
  XSetForeground(_me, _gc, WhitePixel(_me, _screen_num));
  XSetFillStyle(_me, _gc, FillSolid);
  draw_border();
  for_each(snake.begin(), snake.end(), bind1st(std::mem_fun(&Libx::print_snake), this));
  print_head(snake.begin()->x * 20, snake.begin()->y * 20);
  print_food(food.x * 20, food.y * 20);
  speedup(snake.begin()->x, snake.begin()->y, food.x, food.y);
  XFlush(_me);
}

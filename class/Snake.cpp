/*
** Snake.cpp for Snake in /home/mathon_j/rendu/cpp_nibbler/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:39:29 2015 Jérémy MATHON
// Last update Fri Apr  3 14:29:53 2015 simon hure
*/

#include	"../header/Snake.hpp"

Snake::Snake(int const &w, int const &h) : width(w), height(h)
{
  t_snake tmp;

  tmp.x = (w / 2) - 2;
  tmp.y = h / 2;
  this->snake.push_front(tmp);
  tmp.x = (w / 2) - 1;
  tmp.y = h / 2;
  this->snake.push_front(tmp);
  tmp.x = (w / 2);
  tmp.y = h / 2;
  this->snake.push_front(tmp);
  tmp.x = (w / 2) + 1;
  tmp.y = h / 2;
  this->snake.push_front(tmp);
}

const	std::list<t_snake>	Snake::get_snake() const
{
  return (this->snake);
}

std::list<t_snake>		Snake::set_snake()
{
  return (this->snake);
}

const	t_food			Snake::get_food() const
{
  return (this->_food);
}

void				Snake::init_food(int const &x, int const &y)
{
  std::list<t_snake>::iterator	it;

  this->_food.x = rand() % x;
  this->_food.y = rand() % y;
  for (it = this->snake.begin(); it != this->snake.end(); ++it)
    {
      if (it->x == this->_food.x && it->y == this->_food.y)
	this->init_food(x, y);
    }
}

t_snake				Snake::move_dir(t_snake const &snake, e_move const &touch)
{
  t_snake			mov;

  mov = snake;
  switch (touch)
    {
    case LEFT:
      mov.x = mov.x - 1;
      break;
    case RIGHT:
      mov.x++;
      break;
    case UP:
      mov.y = mov.y - 1;
      break;
    case DOWN:
      mov.y++;
      break;
    case NONE:
      break;
    }
  return (mov);
}

void				Snake::check_food(int const &x, int const &y, t_snake const &snake, e_move const &touch)
{
  t_snake	tmp;
  int		new_x;
  int		new_y;

    if (snake.x == this->get_food().x && snake.y == this->get_food().y)
    {
      this->init_food(x, y);
      tmp = move_dir(snake, touch);
      this->snake.push_front(tmp);
    }
  else
    {
      tmp = move_dir(snake, touch);
      this->snake.push_front(tmp);
      this->snake.pop_back();
    }
}

int				Snake::check_eat(int const &x, int const &y, t_snake const &snake)
{
  std::list<t_snake>::iterator	it;

  if (snake.x < 0 || snake.y < 0 || snake.x >= x || snake.y >=y)
    return (-1);
  for (it = this->snake.begin(); it != this->snake.end(); ++it)
    {
      if (it != this->snake.begin() && this->snake.front().x == it->x && this->snake.front().y == it->y)
	return (-1);
    }
  return (0);
}

/*
** Snake.cpp for Snake in /home/mathon_j/rendu/cpp_nibbler/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:39:29 2015 Jérémy MATHON
// Last update Tue Mar 31 17:00:11 2015 Valentin Cardon
*/

#include	"../header/Snake.hpp"

Snake::Snake(int const &w, int const &h) : width(w), height(h)
{
  t_snake tmp;

  tmp.x = (w % 2) - 2;
  tmp.y = h % 2;
  this->snake.push_front(tmp);
  tmp.x = (w % 2) - 1;
  tmp.y = h % 2;
  this->snake.push_front(tmp);
  tmp.x = (w % 2);
  tmp.y = h % 2;
  this->snake.push_front(tmp);
  tmp.x = (w % 2) + 1;
  tmp.y = h % 2;
  this->snake.push_front(tmp);
}

const	std::list<t_snake>	Snake::get_snake() const
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

void				Snake::check_food(int const &x, int const &y)
{
  t_snake tmp;

  if (this->get_snake().front().x == this->get_food().x && this->get_snake().front().x == this->get_food().y)
    {
      this->init_food(x, y);
      tmp.x = x;
      tmp.y = y;
      this->snake.push_front(tmp);
    }
  else
    {
      tmp.x = x;
      tmp.y = y;
      this->snake.push_front(tmp);
      this->snake.pop_back();
    }
}

int				Snake::check_eat(int const &x, int const &y)
{
  std::list<t_snake>::iterator	it;

  if (this->snake.front().x < 0 || this->snake.front().y < 0 || this->snake.front().x >= x || this->snake.front().y >=y)
    return (-1);
  for (it = this->snake.begin(); it != this->snake.end(); ++it)
    {
      if (it != this->snake.begin() && this->snake.front().x == it->x && this->snake.front().y == it->y)
	return (-1);
    }
  return (0);
}

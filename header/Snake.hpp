/*
** Snake.hpp for Snake in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:37:36 2015 Jérémy MATHON
// Last update Wed Apr  1 18:28:01 2015 Valentin Cardon
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include	<iostream>
# include	<list>
# include	<cstdlib>
# include	<time.h>
# include	"IDisplay.hpp"

class	Snake
{
private:
  int			width;
  int			height;
  std::list<t_snake>	snake;
   t_food		_food;

public:
  Snake(int const &, int const &);
  ~Snake() {};
  const std::list<t_snake>	get_snake() const;
  std::list<t_snake>		set_snake();
  const	t_food			get_food() const;
  void				init_food(int const &, int const &);
  void				check_food(int const &, int const &, t_snake const &);
  int				check_eat(int const &, int const &, t_snake const &);
};

#endif /* !SNAKE_HPP_ */

/*
** Snake.hpp for Snake in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:37:36 2015 Jérémy MATHON
** Last update Wed Mar 18 23:13:59 2015 Jérémy MATHON
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include	<iostream>

typedef struct	s_snake
{
  int		x;
  int		y;
}		t_snake;

typedef struct	s_food
{
  int		x;
  int		y;
}		t_food;

class	Snake : public IDisplay {
protected:
  int			width;
  int			height;
  std::list<t_snake>	snake;
  t_food		_food;

public:
  Snake(int const &, int const &);
  ~Snake() {};
  const std::list<t_snake>	&get_snake() const;
  const	t_food			&get_food() const;
  void				init_food(int const &, int const &);
  void				check_food(int const &, int const &);
};

#endif /* !SNAKE_HPP_ */

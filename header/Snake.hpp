/*
** Snake.hpp for Snake in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:37:36 2015 Jérémy MATHON
** Last update Wed Mar 11 10:42:50 2015 Jérémy MATHON
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include	<iostream>

class	Snake : public IDisplay {

  int		width;
  int		height;

public:
  Snake(int const &, int const &);
  ~Snake() {};
};

#endif /* !SNAKE_HPP_ */

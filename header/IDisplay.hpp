/*
** IDisplay.hpp for IDisplay in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:36:06 2015 Jérémy MATHON
** Last update Tue Mar 24 09:07:09 2015 Jérémy MATHON
*/

#ifndef IDISPLAY_HPP_
# define IDISPLAY_HPP_

# include	<iostream>
# include	"Snake.hpp"

class	IDisplay
{
public:
  virtual	void	display(std::list<t_snake> snake, const t_food food) = 0;
  virtual	e_move	move() = 0;
  virtual		~IDisplay() {}
};

typedef	IDisplay	*create_t(int const &, const int &);

#endif /* !IDISPLAY_HPP_ */

/*
** IDisplay.hpp for IDisplay in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Wed Mar 11 10:36:06 2015 Jérémy MATHON
// Last update Tue Mar 24 15:46:09 2015 Valentin Cardon
*/

#ifndef IDISPLAY_HPP_
# define IDISPLAY_HPP_

# include	<iostream>
# include	"../sdl/sdl.hpp"

typedef enum	e_move
  {
    UP,
    RIGHT,
    DOWN,
    LEFT
  }		t_move;

typedef struct s_snake
{
  int		x;
  int		y;
  t_move	move;
}	       t_snake;

typedef struct	s_food
{
  int		x;
  int		y;
}		t_food;

class	IDisplay 
{
public:
  virtual	void	display(std::list<t_snake> snake, const t_food food) = 0;
  virtual	e_move	move() = 0;
  virtual		~IDisplay() {}
  virtual	void	init(const int, const int);	
};

typedef	IDisplay	*create_t(int const &, const int &);

#endif /* !IDISPLAY_HPP_ */

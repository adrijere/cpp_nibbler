/*
** Error.hpp for Error in /home/mathon_j/rendu/cpp_nibbler/header
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Mar 10 18:21:04 2015 Jérémy MATHON
** Last update Tue Mar 10 18:22:27 2015 Jérémy MATHON
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include	<iostream>

class	CoreError : public std::exception {
  std::string	_message;

public:
  CoreError(std::string const &message);
  ~CoreError() throw() {};
  
  const char *what () const throw();
}

#endif /* !ERROR_HPP_ */

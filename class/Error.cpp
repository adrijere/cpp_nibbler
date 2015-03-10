/*
** Error.cpp for Error in /home/mathon_j/rendu/cpp_nibbler/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Mar 10 18:22:40 2015 Jérémy MATHON
** Last update Tue Mar 10 18:23:56 2015 Jérémy MATHON
*/

#include	"Error.hpp"

CoreError::CoreError(std::string const &message) : _message(message {}
const char *CoreError::what() const throw() {
  return this->_message.c_str();
}

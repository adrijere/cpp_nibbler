//
// Exception.cpp for exception in /home/hure_s/tek2/rendu/cpp_nibbler/class
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Fri Apr  3 15:03:08 2015 simon hure
// Last update Fri Apr  3 15:38:19 2015 simon hure
//

#include <cstdlib>
#include "../header/Exception.hh"

Exception::Exception(const std::string &msq) throw() : message(msq)
{

}

Exception::~Exception() throw()
{
  exit(0);
}

const char * Exception::what() const throw()
{
  return (this->message.data());
}

DlException::DlException(const std::string &msq) throw() : Exception(msq)
{
  std::cerr << "Dl loader Error : ";
}

DlException::~DlException() throw()
{

}

DisplayException::DisplayException(const std::string &msq) throw() : Exception(msq)
{
  std::cerr << "Display Error : ";
}

DisplayException::~DisplayException() throw()
{

}

ArgumentException::ArgumentException(const std::string &msq) throw() : Exception(msq)
{
  std::cerr << "Argument Error : ";
}

ArgumentException::~ArgumentException() throw()
{

}


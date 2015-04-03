//
// Exception.hh for exception in /home/hure_s/tek2/rendu/cpp_nibbler/header
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Fri Apr  3 15:11:37 2015 simon hure
// Last update Fri Apr  3 15:18:23 2015 simon hure
//

#ifndef _EXCEPTION_HH_
#define _EXCEPTION_HH_

#include <string>
#include <iostream>
#include <exception>

class Exception : public std::exception
{
protected:
  std::string message;
public:
  Exception(const std::string &msg) throw();
  virtual const char * what() const throw();
  virtual ~Exception() throw();
};

class DlException : public Exception
{
public:
  DlException(const std::string &msg) throw();
  virtual ~DlException() throw();
};

class DisplayException : public Exception
{
public:
  DisplayException(const std::string &msg) throw();
  virtual ~DisplayException() throw();
};

class ArgumentException : public Exception
{
public:
  ArgumentException(const std::string &msg) throw();
  virtual ~ArgumentException() throw();
};

#endif

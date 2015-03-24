//
// Init.hh for init in /home/hure_s/tek2/rendu/cpp_nibbler/header
// 
// Made by simon hure
// Login   <hure_s@epitech.net>
// 
// Started on  Tue Mar 24 13:03:50 2015 simon hure
// Last update Tue Mar 24 13:54:39 2015 simon hure
//

#ifndef _INIT_HH_
#define _INIT_HH_

#include <iostream>
#include <string>
#include <sstream>

class Init
{
public:
  Init();
  int	start(int ac, char **av);
  int	check_arg(int const &x, int const &y, const std::string &lib);
};

#endif

/*
** Librairy.cpp for Librairy in /home/mathon_j/rendu/cpp_nibbler/class
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Tue Mar 24 09:16:12 2015 Jérémy MATHON
** Last update Tue Mar 24 09:27:56 2015 Jérémy MATHON
*/

#include	<string>
#include	<dlfcn.h>
#include	"IDisplay.hpp"

int		loop_game(int const &, int const &, IDisplay *);

int		check_lib(const void *lib)
{
  if (!lib)
    {
      std::cerr << "Cannot load library : " << dlerror() << std::endl;
      return (1);
    }
  return (0);
}

int		check_symbol(const char *dlsysm_error)
{
  if (dlsysm_error)
    {
      std::cerr << "Cannot load symbol : " << dlsysm_error << std::endl;
      return (1);
    }
  return (0);
}

int		load_library(int const &width, int const &height, std::string const namelib)
{
  void		*lib;

  std::string *tmp = new std::string("./");
  *tmp = *tmp + namelib;
  lib = dlopen(tmp->c_str(), RTLD_LAZY);
  if ((check_lib(lib)) == 1)
    return (1);
  dlerror();
  create_t *create_display = (create_t*)dlsym(lib, "create");
  char const dlsym_error = dlerror();
  if ((check_symbol(dlsym_error)) == 1)
    return (1);
  IDisplay *Win = create_display(width, height);
  loop_game(width, height, Win);
  delete Win;
  dlclose(lib);
  return (0);
}

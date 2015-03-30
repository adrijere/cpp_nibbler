##
## Makefile for cpp_nibbler in /home/mathon_j/rendu/cpp_nibbler
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Tue Mar 24 09:51:26 2015 Jérémy MATHON
## Last update Mon Mar 30 15:26:01 2015 simon hure
##

BIN		=	nibbler

SDL_NAME	=	lib_nibbler_sdl.so
OPENGL_NAME	=	lib_nibbler_opengl.so
NCURSES_NAME	=	lib_nibbler_ncurses.so

SDL_PATH	=	./sdl/
OPENGL_PATH	=	./opengl/
NCURSES_PATH	=	./ncurses/

SRC		=	./class/Library.cpp	\
			./class/Snake.cpp	\
			./class/main.cpp	\
			./class/Init.cpp

#SDL_SRC		=	./sdl/init_sdl.cpp	\
#OPENGL_SRC	=
NCURSES_SRC	=	./ncurses/init_ncurses.cpp 

#SDL_OBJ		=	$(SDL_SRC:.cpp=.o)
#OPENGL_OBJ	=	$(OPENGL_SRC:.cpp=.o)
NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)

CC		=	clang++

CXXFLAGS	+=	-Wall -Wextra -fpic -I ./

#SDL_LDFLAGS	+=	-shared -lSDL
#OPENGL_LDFLAGS	+=	-shared -lSDl -lGL -lGLU
NCURSES_LDFLAGS	+=	-shared -lncurses

all:			$(NCURSES_NAME)

#$(SDL_NAME):		$(SDL_OBJ)
#			$(CC) $(SDL_OBJ) -o $(SDL_NAME) $(SDL_LDFLAGS)

#$(OPENGL_NAME):		$(OPENGL_OBJ)
#			$(CC) $(OPENGL_OBJ) -o $(OPENGL_NAME) $(OPENGL_LDFLAGS)

$(NCURSES_NAME):	$(NCURSES_OBJ)
			$(CC) $(NCURSES_OBJ) -o $(NCURSES_NAME) $(NCURSES_LDFLAGS)
			clang++ $(SRC) -ldl -I ./ -o $(BIN)


clean:
			rm -f $(NCURSES_OBJ) $(BIN)

fclean:			clean
			rm -f $(NCURSES_NAME)

re:			fclean all

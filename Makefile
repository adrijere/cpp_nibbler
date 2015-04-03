##
## Makefile for cpp_nibbler in /home/mathon_j/rendu/cpp_nibbler
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Tue Mar 24 09:51:26 2015 Jérémy MATHON
## Last update Fri Apr  3 13:35:13 2015 Jérémy MATHON
##

BIN		=	nibbler

SDL_NAME	=	lib_nibbler_sdl.so
XLIB_NAME	=	lib_nibbler_xlib.so
NCURSES_NAME	=	lib_nibbler_ncurses.so

SDL_PATH	=	./sdl/
XLIB_PATH	=	./libx/
NCURSES_PATH	=	./ncurses/

SRC		=	./class/Library.cpp	\
			./class/Snake.cpp	\
			./class/main.cpp	\
			./class/Init.cpp

OBJ		=	$(SRC:.cpp=.o)

SDL_SRC		=	./sdl/init_sdl.cpp	
XLIB_SRC	=	./libx/init_libx.cpp	
NCURSES_SRC	=	./ncurses/init_ncurses.cpp 

SDL_OBJ		=	$(SDL_SRC:.cpp=.o)
XLIB_OBJ	=	$(XLIB_SRC:.cpp=.o)
NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)

CC		=	g++

CXXFLAGS	+=	-fpic -I ./

SDL_LDFLAGS	+=	-shared -lSDL
XLIB_LDFLAGS	+=	-shared -lX11
NCURSES_LDFLAGS	+=	-shared -lncurses

all:			$(NCURSES_NAME) $(SDL_NAME) $(XLIB_NAME) $(BIN)

$(SDL_NAME):		$(SDL_OBJ)
			$(CC) $(SDL_OBJ) -o $(SDL_NAME) $(SDL_LDFLAGS)

$(XLIB_NAME):		$(XLIB_OBJ)
			$(CC) $(XLIB_OBJ) -o $(XLIB_NAME) $(XLIB_LDFLAGS)

$(NCURSES_NAME):	$(NCURSES_OBJ)
			$(CC) $(NCURSES_OBJ) -o $(NCURSES_NAME) $(NCURSES_LDFLAGS)

$(BIN):			$(OBJ)
			$(CC) $(OBJ) -ldl -I ./ -o $(BIN)

clean:
			rm -f $(NCURSES_OBJ) $(SDL_OBJ) $(XLIB_OBJ) $(OBJ)

fclean:			clean
			rm -f $(NCURSES_NAME) $(SDL_NAME) $(XLIB_NAME) $(BIN)

re:			fclean all

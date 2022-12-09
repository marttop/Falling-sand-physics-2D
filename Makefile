NAME	=	test_game

CC	=	g++

SRC	=	src/main.cpp\
		src/engine/Core.cpp

DEBUG_LEVEL     = -g3
EXTRA_CCFLAGS   = -Wall
COMPILEFLAGS	= -std=c++17
CCFLAGS			+= -I/src/engine
RAYLIBFLAGS		= `pkg-config --libs --cflags raylib`
CXXFLAGS        = $(COMPILEFLAGS) $(DEBUG_LEVEL) $(EXTRA_CCFLAGS) $(RAYLIBFLAGS)
CCFLAGS         = $(CXXFLAGS)

OBJ	=	$(SRC:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(RAYLIBFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
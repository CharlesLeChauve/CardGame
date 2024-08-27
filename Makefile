NAME	=	Cyberogue
GCC		=	c++
FLAGS 	=	-g -Wall -Werror -Werror -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0
SRC 	=	Card.cpp Collection.cpp Deck.cpp Enemy.cpp Player.cpp main.cpp
OBJ 	=	$(patsubst %.cpp,%.o,$(SRC))
RM 		=	rm -f

.SUFFIXES: .c .o

$(NAME): $(OBJ)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@ 

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Done\n"

fclean: clean
	@echo "Deleting cub3D executable..."
	@rm -f $(NAME)
	@echo "Done\n"

re: fclean all

.PHONY: all do_configure clean fclean re
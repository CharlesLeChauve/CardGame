NAME	=	Cyberogue
GCC		=	c++
FLAGS 	=	-g -Wall -Werror -Werror
SRC 	=	$(wildcard *.cpp)
OBJ 	=	$(patsubst %.cpp,%.o,$(SRC))
RM 		=	rm -f

.SUFFIXES: .c .o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

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
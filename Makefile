# Variables
NAME    = Cyberogue
CXX     = g++
CXXFLAGS = -g -std=c++23 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC     = ${wildcard src/*.cpp}
OBJS     = $(SRC:.cpp=.o)
RM      = rm -f

# Cible par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o game $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJS)
	@echo "Done"

# Nettoyage complet (objets + exécutable)
fclean: clean
	@$(RM) $(NAME)
	@echo "Done"

# Nettoyage complet + recompilation
re: fclean all

# Cibles "Phony" pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re

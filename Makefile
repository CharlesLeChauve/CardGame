# Variables
NAME    = Cyberogue
CXX     = c++
FLAGS   = -g -std=c++17 #-Wall -Werror
SRC     = Buff.cpp BuffFactory.cpp FightInstance.cpp TermDisplay.cpp CEffects.cpp EffectFactory.cpp Card.cpp Deck.cpp ACharacter.cpp Enemy.cpp Player.cpp main.cpp Collection.cpp
OBJ     = $(SRC:.cpp=.o)
RM      = rm -f

# Cible par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

# Création des fichiers objets
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJ)
	@echo "Done"

# Nettoyage complet (objets + exécutable)
fclean: clean
	@$(RM) $(NAME)
	@echo "Done"

# Nettoyage complet + recompilation
re: fclean all

# Cibles "Phony" pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re

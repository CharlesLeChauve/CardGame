// #include "Card.hpp"
// #include "IEffect.hpp"
// #include "Collection.hpp"
// #include "EffectRegistry.hpp"
// #include "EffectFactory.hpp"
// #include "CEffects.hpp"
// #include "ACharacter.hpp"
// #include "Deck.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "EffectFactory.hpp"
#include "TermDisplay.hpp"
#include "FightInstance.hpp"
#include "Buff.hpp"
#include "Logger.hpp"

int main(void)
{
	registerAllBuffs();
	registerAllEffects();
	// Collection& collection = Collection::getInstance();
	// Deck deck;

	// deck.printDeck();
	// deck.shuffle();
	// deck.printDeck();
	std::cout << "Welcome in CybeRogue !" << std::endl;
	std::cout << "Please select a name : ";
	std::string playerName;
	std::getline(std::cin, playerName);
	Player player(playerName);

	while (1)
	{
		std::cout << "Choose your enemy : ";
		std::string enemyName;
		std::getline(std::cin, enemyName);  // Lecture de la ligne
		
		// Si l'input est vide, on redemande
		if (enemyName.empty()) {
			std::cerr << "Invalid input. Please enter a valid enemy name." << std::endl;
			continue ;
		}
		else if (enemyName.compare("END") == 0)
			break;
		try {
			Enemy enemy(enemyName);
			FightInstance fight = FightInstance(player, enemy);
			fight.handleFight();
		}
		catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
			continue ;
		}
		Logger::getInstance().clearLog();
	}

}
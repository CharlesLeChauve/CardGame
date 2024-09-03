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

int main(void)
{
	registerAllEffects();
	Collection& collection = Collection::initialize("cards.json");
	// Deck deck;

	// deck.printDeck();
	// deck.shuffle();
	// deck.printDeck();
	collection.getInstance();
	std::cout << "Welcome in CybeRogue !" << std::endl;
	std::cout << "Please select a name : ";
	std::string playerName;
	std::getline(std::cin, playerName);
	Player player(playerName);

	while (1)
	{
		std::cout << "Choose your enemy : ";
		std::string enemyName;
		std::getline(std::cin, enemyName);
		Enemy enemy(enemyName);
		FightInstance fight = FightInstance(player, enemy);
		fight.handleFight();
	}

}
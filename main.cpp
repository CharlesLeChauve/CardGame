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

int main(void)
{
	registerAllEffects();
	Collection& collection = Collection::initialize("cards.json");
	// Deck deck;

	// deck.printDeck();
	// deck.shuffle();
	// deck.printDeck();
	collection.getInstance();
	Enemy enemy("Hippie");
	Player player("Me");

	while (player.getHP() > 0 && enemy.getHP() > 0)
	{
	// std::cout << player.getHP() << std::endl;
	// std::cout << enemy.getHP() << std::endl;
		player.playTurn(enemy);
	}
}
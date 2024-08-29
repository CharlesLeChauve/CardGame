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
	player.draw();
	player.draw();
	player.draw();
	player.draw();
	player.draw();
	player.printHand();
	player.hand[0]->getName();
	player.use(*(player.hand[0]), enemy, 0);
	player.use(*(player.hand[0]), enemy, 0);
	player.use(*(player.hand[0]), enemy, 0);
	player.use(*(player.hand[0]), enemy, 0);
	player.use(*(player.hand[0]), enemy, 0);
	std::cout << player.getHP() << std::endl;
	std::cout << enemy.getHP() << std::endl;
}
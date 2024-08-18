#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Collection.hpp"

int main(void)
{
	Collection& collection = Collection::initialize("cards.json");
	Deck deck;

	deck.printDeck();
	deck.shuffle();
	deck.printDeck();

	// Player player("Me");
	// player.draw();
	// player.printHand();	
}
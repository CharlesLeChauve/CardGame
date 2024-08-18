#pragma once
#include <iostream>
#include "Card.hpp"
#include "Collection.hpp"
#include <algorithm>
#include <random>

class Deck
{
private:
	std::vector<Card> cards;
public:
	Deck();
	~Deck();

	void	shuffle();
	void	addCard(Card* card);
	void	removeCard(Card* card);
	void    printDeck();
	Card*	draw();
};

Deck::Deck() {
	Collection& collection = Collection::getInstance();
	cards.emplace_back(collection.getRandomCard());
	cards.emplace_back(collection.getRandomCard());
	cards.emplace_back(collection.getRandomCard());
	cards.emplace_back(collection.getRandomCard());
	cards.emplace_back(collection.getRandomCard());
}

Deck::~Deck()
{
}

void    Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(this->cards.begin(), this->cards.end(), g);
}

void    Deck::printDeck()
{
	for (const auto& card : cards)
		std::cout << card.getName() << std::endl;
}

Card*	Deck::draw()
{
	Card	*card = new Card(cards[0]);
	this->cards.erase(cards.begin());
	return card;
}

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Deck.hpp"

using json = nlohmann::json;

class Player
{
private:
	std::string	name;
	int		hp;
	int		handSize;
	Deck	deck;
	std::vector<Card> hand;
	std::vector<Card> discardPile;
public:
	Player(std::string name);
	~Player();

	void	draw();
	void	printHand();
	void	takeDamage(int damage);
	void	shuffleDiscard();
};

Player::Player(std::string name) : hand{}, discardPile{}, deck{}, hp{100}, name{name}, handSize{100} {}

Player::~Player()
{
}

void Player::draw()
{
	if (deck.getSize() == 0)
	{
		if (discardPile.size() == 0)
		{
			std::cout << "No more card to draw...";
			return ;
		}
		this->shuffleDiscard();
	}
	if (hand.size() >= this->handSize)
		discardPile.push_back(deck.draw());
	else
		hand.push_back(deck.draw());	
}

void    Player::printHand()
{
    for (const auto& card : hand)
        std::cout << card.getName() << std::endl;
}

void	Player::takeDamage(int damage)
{
	this->hp -= damage;
    std::cout << "Player takes " << damage << " damage! Health: " << hp << std::endl;

}

void	Player::shuffleDiscard()
{
	std::cout << "Shuffling Deck" << std::endl;
	while (discardPile.size() > 0)
	{
		deck.addCard(discardPile[0]);
		discardPile.erase(discardPile.begin());
	}
	deck.shuffle();
}

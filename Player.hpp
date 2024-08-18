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
	Deck		*deck;
	std::vector<Card *> hand;
	std::vector<Card *> discardPile;
public:
	Player(std::string name);
	~Player();

	void	draw();
	void	printHand();
	void	takeDamage(int damage);
};

Player::Player(std::string name) : hand{}, discardPile{}
{
	this->deck = new Deck();
	this->name = name;
	this->hp = 100;
}

Player::~Player()
{
}

void Player::draw()
{
	hand.push_back(deck->draw());	
}

void    Player::printHand()
{
    for (const auto& card : hand)
        std::cout << card->getName() << std::endl;
}

void	Player::takeDamage(int damage)
{
	this->hp -= damage;
}
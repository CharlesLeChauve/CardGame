#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Card
{
private:
	std::string	name;
	int			cost;
	std::string effect;
	std::string description;
public:
	Card(std::string name, int cost, std::string effect, std::string description);
	~Card();
	const std::string&	getName() const;
};

Card::Card(std::string name, int cost, std::string effect, std::string description)
        : name(name), cost(cost), effect(effect), description(description) {}

Card::~Card() {}

const std::string&	Card::getName() const
{
	return (this->name);
}

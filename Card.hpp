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
	//Card(std::string name);
	Card(std::string name, int cost, std::string effect, std::string description);
	Card();
	~Card();

	// Use();
	const std::string&	getName() const;
};

Card::Card() : name("TheZeroCard") {
	std::cout << "Construct card : " << this->name << std::endl; 
}

Card::Card(std::string name, int cost, std::string effect, std::string description)
        : name(name), cost(cost), effect(effect), description(description) {}

// Card::Card(std::string name) : name(name) {
// 	std::ifstream file("cards.json");
// 	if (!file.is_open()) {
// 		throw std::runtime_error("Could not open cards.json");
//     }
//     json j;
//     file >> j;
//     file.close();

// 	auto card_info = j["cards"][this->name];
//     cost = card_info["cost"];
//     effect = card_info["effect"];
//     description = card_info["description"];
// 	//set_effect_function(this->getName() + "_effect");	
// 	std::cout << "Construct card : " << this->name << std::endl; 
// }

Card::~Card() {}

const std::string&	Card::getName() const
{
	return (this->name);
}

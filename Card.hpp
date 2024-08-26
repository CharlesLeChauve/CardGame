#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "json.hpp"

class ACharacter;
class IEffect;

using json = nlohmann::json;

class Card
{
protected:
	std::string	name;
	int			cost;
	std::string	description;

	// Méthode virtuelle pure pour définir l'effet de la carte dans les classes dérivées
	std::vector<std::unique_ptr<IEffect>> effects;

public:
	Card(std::string name, int cost, std::string description);
    void addEffect(std::unique_ptr<IEffect> effect);
    void applyEffects(ACharacter& target, ACharacter& player) const;
    const std::string& getName() const;
};

Card::Card(std::string name, int cost, std::string description)
    : name(std::move(name)), cost(cost), description(std::move(description)) {}

void Card::addEffect(std::unique_ptr<IEffect> effect) {
    effects.push_back(std::move(effect));
}

void Card::applyEffects(ACharacter& target, ACharacter& player) const {
    for (const auto& effect : effects) {
        effect->apply(target);
    }
}

const std::string& Card::getName() const {
    return name;
}
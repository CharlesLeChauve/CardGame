#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "json.hpp"
#include "IEffect.hpp"

class ACharacter;
// class IEffect;

using json = nlohmann::json;

class Card
{
protected:
	std::string	name;
	int			cost;
	std::string	description;

	std::vector<IEffect*> effects;

public:
	Card(std::string name, int cost, std::string description);
    void addEffect(IEffect* effect);
    void applyEffects(ACharacter& target, ACharacter& player) const;
    const std::string& getName() const;
};

Card::Card(std::string name, int cost, std::string description)
    : name(std::move(name)), cost(cost), description(std::move(description)) {}

void Card::addEffect(IEffect* effect) {
    effects.push_back(effect);
}

void Card::applyEffects(ACharacter& target, ACharacter& player) const {
    for (const auto* effect : effects) {
        effect->apply(target);
    }
}

const std::string& Card::getName() const {
    return name;
}
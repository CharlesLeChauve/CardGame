#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include "json.hpp"
#include "IEffect.hpp"

class ACharacter;

using json = nlohmann::json;

enum class TargetType {
    Holder,  // Le joueur qui utilise la carte
    Opponent // L'adversaire
};

struct TargetedEffect {
    IEffect* effect;
    TargetType target;
};

class Card
{
protected:
	std::string	name;
	int			cost;
	std::string	description;

	std::vector<TargetedEffect> effects;

public:
	Card(std::string name, int cost, std::string description);
    void addEffect(IEffect* effect, std::string target_type);
    void applyEffects(ACharacter& holder, ACharacter& opponent) const ;
    const std::string& getName() const;
	const std::string& getDescription() const;
    int getCost() const;
    // const std::vector<IEffect*>& getEffects() const;
};

#pragma once

#include <iostream>
#include "Card.hpp"
#include "ACharacter.hpp"

class Enemy : public ACharacter {
public:
    Enemy(const std::string& name);
    ~Enemy();

    // Implémentation des méthodes virtuelles pures de ACharacter
    void use(Card& card, ACharacter& target, int index) override;
    void performSpecialAbility() override;
};

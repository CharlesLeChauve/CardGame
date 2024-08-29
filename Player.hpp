#pragma once

#include <iostream>
#include "Card.hpp"
#include "ACharacter.hpp"

class Player : public ACharacter {
public:
    Player(const std::string& name);
    ~Player();

    // Implémentation des méthodes virtuelles pures de ACharacter
    void use(Card& card, ACharacter& opponent, int index) override;
    void performSpecialAbility() override;
};

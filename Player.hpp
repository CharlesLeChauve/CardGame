#pragma once

#include <iostream>
#include "Card.hpp"
#include "ACharacter.hpp"

class Player : public ACharacter {
public:
    Player(const std::string& name);
    ~Player();

    // Implémentation des méthodes virtuelles pures de ACharacter
    void performSpecialAbility() override;

    //turn method
    void playTurn(ACharacter& opponent);
};

#pragma once

#include <iostream>
#include "Card.hpp"
#include "ACharacter.hpp"

class Player : public ACharacter {
public:
    Player(const std::string& name);
    ~Player();

    // Implémentation des méthodes virtuelles pures de ACharacter
    void use(Card& card, ACharacter& target) override;
    void performSpecialAbility() override;
};

// Constructeur
Player::Player(const std::string& name)
    : ACharacter(name, 100, 5)  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
}

// Destructeur
Player::~Player() = default;

// Implémentation de la méthode virtuelle pure 'use' depuis ACharacter
void Player::use(Card& card, ACharacter& target) {
    std::cout << getName() << " uses " << card.getName() << " on " << target.getName() << std::endl;
    card.applyEffects(target, *this);  // Applique l'effet de la carte
}

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Player::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}


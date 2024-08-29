#include "Enemy.hpp"

// Constructeur
Enemy::Enemy(const std::string& name)
    : ACharacter(name, 100, 5)  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
}

// Destructeur
Enemy::~Enemy() = default;

// Implémentation de la méthode virtuelle pure 'use' depuis ACharacter
void Enemy::use(Card& card, ACharacter& target, int index) {
    std::cout << getName() << " uses " << card.getName() << " on " << target.getName() << std::endl;
    card.applyEffects(target, *this);  // Applique l'effet de la carte
}

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Enemy::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}


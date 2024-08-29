#include "Player.hpp"

// Constructeur
Player::Player(const std::string& name)
    : ACharacter(name, 100, 5)  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
}

// Destructeur
Player::~Player() = default;

// Implémentation de la méthode virtuelle pure 'use' depuis ACharacter
void Player::use(Card& card, ACharacter& opponent, int index) {
    std::cout << getName() << " uses " << card.getName() << " on " << opponent.getName() << std::endl;
    if (index < hand.size()) {
            // 1. Utiliser les effets de la carte
            hand[index]->applyEffects(*this, opponent); // Appel de la méthode 'applyEffects' de la carte

            // 2. Déplacer la carte vers la discardPile
            discardPile.push_back(std::move(hand[index]));

            // 3. Supprimer l'élément nul du vector hand
            hand.erase(hand.begin() + index);
        } else {
            std::cerr << "Invalid card index" << std::endl;
        }
}

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Player::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}


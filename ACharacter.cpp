#include "ACharacter.hpp"

// Constructeur
ACharacter::ACharacter(const std::string& name, int max_hp, int hand_size)
    : name(name), deck(), fury(0), max_hp(max_hp), hand_size(hand_size), hp(max_hp), discardPile() {}

// Destructeur
ACharacter::~ACharacter() = default;

// Méthodes communes à tous les personnages
int ACharacter::getHP() const {
    return hp;
}

int ACharacter::getMaxHP() const {
    return max_hp;
}

const std::string& ACharacter::getName() const {
    return name;
}

void ACharacter::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

void ACharacter::heal(int amount) {
    hp += amount;
    //if (hp > max_hp) hp = max_hp;
}

// Gestion de la mécanique de jeu (exemple avec Fury)
int ACharacter::getFury() const {
    return fury;
}

void ACharacter::increaseFury(int amount) {
    fury += amount;
}

// Gestion du deck, de la main et de la pile de défausse
void ACharacter::draw() {
    if (deck.getSize() == 0) {
        if (discardPile.empty()) {
            std::cout << "No more cards to draw..." << std::endl;
            return;
        }
        shuffleDiscard();
    }
    if (hand.size() >= static_cast<size_t>(hand_size))
        discardPile.push_back(deck.draw());
    else
        hand.push_back(deck.draw());
}

void ACharacter::printHand() const {
    for (const auto& card : hand)
    {
        if (card) {
            std::cout << card->getName() << std::endl;
            std::cout << card->getDescription() << std::endl;

            // for (const auto& effect : card->getEffects())
            // {
            //     if (effect) {
            //         std::cout << effect->getDescription() << std::endl;
            //     } else {
            //         std::cerr << "Warning: Null effect encountered." << std::endl;
            //     }
            // }
        } else {
            std::cerr << "Warning: Null card encountered in hand." << std::endl;
        }
    }
}

void ACharacter::shuffleDiscard() {
    std::cout << "Shuffling discard pile into deck..." << std::endl;
    while (!discardPile.empty()) {
        deck.addCard(std::move(discardPile.back()));
        discardPile.pop_back();
    }
    deck.shuffle();
}

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Deck.hpp"
#include "Card.hpp"

class ACharacter {
protected:
    std::string name;
    int hp;
    int max_hp;
    int hand_size;
    Deck deck;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> discardPile;
    int fury;

public:
    ACharacter(const std::string& name, int max_hp, int hand_size);
    virtual ~ACharacter();

    // Méthodes communes à tous les personnages
    int getHP() const;
    int getMaxHP() const;
    const std::string& getName() const;
    
    void takeDamage(int damage);
    void heal(int amount);
    
    int getFury() const;
    void increaseFury(int amount);

    // Gestion du deck, de la main et de la pile de défausse
    virtual void draw();
    virtual void printHand() const;
    virtual void shuffleDiscard();

    // Méthodes virtuelles pures
    virtual void use(Card& card, ACharacter& target) = 0;
    virtual void performSpecialAbility() = 0;
};

#include "ACharacter.hpp"

// Constructeur
ACharacter::ACharacter(const std::string& name, int max_hp, int hand_size)
    : name(name), hp(max_hp), max_hp(max_hp), hand_size(hand_size), fury(0), deck(), hand(), discardPile() {}

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
    if (hp > max_hp) hp = max_hp;
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
        std::cout << card->getName() << std::endl;
}

void ACharacter::shuffleDiscard() {
    std::cout << "Shuffling discard pile into deck..." << std::endl;
    while (!discardPile.empty()) {
        deck.addCard(std::move(discardPile.back()));
        discardPile.pop_back();
    }
    deck.shuffle();
}

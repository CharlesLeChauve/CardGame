#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Deck.hpp"
#include "Card.hpp"

class ACharacter {
public:
    std::string name;
    Deck deck;
    int fury;
    int max_hp;
    int hand_size;
    int hp;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> discardPile;
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
    virtual void drawN(int n);
    virtual void printHand() const;
    virtual void shuffleDiscard();

    // Méthodes virtuelles pures
    virtual void use(Card& card, ACharacter& target, int index) = 0;
    virtual void performSpecialAbility() = 0;
};

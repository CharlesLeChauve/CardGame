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
    int max_hp;
    int hand_size;
    int hp;
    int energyCapacity;
    int energy;
    std::vector<std::unique_ptr<Card>> hand;
    std::vector<std::unique_ptr<Card>> discardPile;
    std::map<std::string, int> buffs;
    ACharacter(const std::string& name, int max_hp, int hand_size);
    virtual ~ACharacter();

    // Méthodes communes à tous les personnages
    int getHP() const;
    int getMaxHP() const;
    int getEnergy() const;
    int getEnergyCap() const;
    const std::string& getName() const;

    void addBuff(std::string type, int amount);
    
    void takeDamage(int damage);
    void heal(int amount);
    
    int getFury() const;

    int getBuffAmount(const std::string& type) const;
    void use(Card& card, ACharacter& target, int index);

    // Gestion du deck, de la main et de la pile de défausse
    virtual void draw();
    virtual void drawN(int n);
	virtual void discardAll();
    virtual void printHand() const;
    virtual void shuffleDiscard();

    // Méthodes virtuelles pures
    virtual void performSpecialAbility() = 0;
};

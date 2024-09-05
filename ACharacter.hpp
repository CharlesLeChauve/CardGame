#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Deck.hpp"
#include "Card.hpp"
#include "Buff.hpp"
#include "BuffFactory.hpp"
#include "Logger.hpp"

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
    std::vector<Buff*> buffs;
    ACharacter(const std::string& name, int max_hp, std::string baseDeck);
    virtual ~ACharacter();

    // Méthodes communes à tous les personnages
    int getHP() const;
    int getMaxHP() const;
    int getEnergy() const;
    int getEnergyCap() const;
    const std::string& getName() const;

    void addBuff(std::string type, int amount);
    void discardBuffs();
    
    void takeDamage(int damage);
    void heal(int amount);

    int getBuffAmount(const std::string& type) const;
    void buffAdjust();
    void use(Card& card, ACharacter& target, int index);

    // Gestion du deck, de la main et de la pile de défausse
    virtual void draw();
    virtual void drawN(int n);
	virtual void discardAll();
    virtual void printHand() const;
    virtual void shuffleDiscard();
    virtual void playTurn(ACharacter& opponent) = 0;

    // Méthodes virtuelles pures
    virtual void performSpecialAbility() = 0;
};

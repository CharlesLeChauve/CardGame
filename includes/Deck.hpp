#pragma once
#include <iostream>
#include <vector>
#include <memory>  // Pour std::unique_ptr
#include <algorithm>
#include <random>
#include "Collection.hpp"

class Cards;

class Deck
{
private:
    // Stockage des cartes avec des pointeurs intelligents
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck();
    Deck(const std::string& prefab);
    ~Deck();

    void shuffle();
    void addCard(std::unique_ptr<Card> card);
    void removeCard();
    void printDeck() const;
    int getSize() const;
    std::unique_ptr<Card> draw();  // Retourne un unique_ptr pour la carte piochée
};

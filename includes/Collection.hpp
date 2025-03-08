#pragma once
#include <iostream>
#include "Card.hpp"
#include <map>
#include <memory>
#include <algorithm>
#include <random>

using json = nlohmann::json;

class Collection {
private:
    static Collection* instance;
    std::map<std::string, Card> card_map;
    Collection(const std::string& file_name);

public:
    static Collection &getInstance();

    // Retourne une copie de la carte -- "Clone() dans le design Pattern Factory"
    std::unique_ptr<Card> getCard(const std::string& card_name) const;

    // Retourne une carte aléatoire
    std::unique_ptr<Card> getRandomCard() const;

    // Supprimer le constructeur de copie et l'opérateur d'affectation
    Collection(const Collection&) = delete;
    Collection& operator=(const Collection&) = delete;
};

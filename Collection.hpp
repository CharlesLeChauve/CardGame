#pragma once
#include <iostream>
#include <fstream>
#include "Card.hpp"
#include <map>
#include <memory>
#include "Deck.hpp"
#include <algorithm>
#include <random>
#include "json.hpp"

using json = nlohmann::json;

class Collection {
private:
    static Collection& instance;
    std::map<std::string, Card> card_map;  // Map de pointeurs uniques
    Collection(const std::string& file_name);

public:
    // Initialisation de l'instance unique
    static Collection &initialize(const std::string file_name) {
        static Collection instance(file_name);
        return instance;
    }

    // Retourne l'instance unique
    static Collection &getInstance() {
        return initialize("cards.json");
    }

    // Retourne une copie de la carte
    std::unique_ptr<Card> getCard(const std::string& card_name) const;

    // Retourne une carte aléatoire
    std::unique_ptr<Card> getRandomCard() const;

    // Supprimer le constructeur de copie et l'opérateur d'affectation
    Collection(const Collection&) = delete;
    Collection& operator=(const Collection&) = delete;
};

Collection::Collection(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open " + file_name);
    }

    json j;
    file >> j;
    file.close();

    for (const auto& item : j["cards"].items()) {
        std::string key = item.key();
        auto value = item.value();
        std::string name = key;
        int cost = value["cost"];
        std::string effect = value["effect"];
        std::string description = value["description"];

        // Création d'une nouvelle carte dans la map avec un unique_ptr
        card_map[name] = Card(name, cost, description);
    }
}

std::unique_ptr<Card> Collection::getCard(const std::string& card_name) const {
    auto it = card_map.find(card_name);
    if (it != card_map.end()) {
        // Retourner une copie de la carte
        return std::make_unique<Card>(it->second);  // Clone de la carte
    } else {
        throw std::runtime_error("Card not found: " + card_name);
    }
}

std::unique_ptr<Card> Collection::getRandomCard() const {
    if (card_map.empty()) {
        throw std::runtime_error("No cards in the collection");
    }

    std::vector<const Card*> cards;
    for (const auto& pair : card_map) {
        cards.push_back(&pair.second);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, cards.size() - 1);

    // Retourner une copie de la carte choisie
    return std::make_unique<Card>(*cards[dis(gen)]);  // Clone de la carte
}

#pragma once
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include <algorithm>
#include <random>

class Collection {
private:
	static Collection& instance;
    std::map<std::string, Card> card_map;
    Collection(const std::string& file_name) {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open " + file_name);
        }

        json j;
        file >> j;
        file.close();

        for (auto& [key, value] : j["cards"].items()) {
            std::string name = key;
            int cost = value["cost"];
            std::string effect = value["effect"];
            std::string description = value["description"];

            // Ajouter la carte à la map
            card_map[name] = Card(name, cost, effect, description);
        }
    }
public:
	static Collection &initialize(const std::string file_name) {
		static Collection instance(file_name);
		return instance;
	}
	static Collection &getInstance() {
		return (initialize("cards.json"));
	}

    // Méthode pour obtenir une copie de la carte par nom
    Card getCard(const std::string& card_name) const {
        auto it = card_map.find(card_name);
        if (it != card_map.end()) {
            return it->second; // Renvoie une copie de la carte
        } else {
            throw std::runtime_error("Card not found: " + card_name);
        }
    }

	Card getRandomCard() const {
		std::vector<Card> cards;
		for (const auto& pair : this->card_map) {
    	    cards.push_back(pair.second);
    	}
		std::random_device rd;
    	std::mt19937 gen(rd());
    	std::uniform_int_distribution<> dis(0, cards.size() - 1);
		return cards[dis(gen)];
	}

	Collection(const Collection&) = delete;
	Collection& operator=(const Collection&) = delete;
};
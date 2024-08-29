#include "EffectFactory.hpp"
#include "Collection.hpp"
#include <fstream>
#include "EffectFactory.hpp"
#include "Collection.hpp"

Collection::Collection(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open " + file_name);
    }

    json j;
    file >> j;
    file.close();

    if (!j.contains("cards") || !j["cards"].is_object()) {
        throw std::runtime_error("Invalid or missing 'cards' field in JSON.");
    }

    for (const auto& item : j["cards"].items()) {
        std::string key = item.key();
        auto value = item.value();

        if (!value.contains("cost") || !value["cost"].is_number_integer() ||
            !value.contains("effects") || !value["effects"].is_array() ||
            !value.contains("description") || !value["description"].is_string()) {
            throw std::runtime_error("Invalid card format for card: " + key);
        }

        std::string name = key;
        int cost = value["cost"];
        std::string description = value["description"];

        // Création d'une nouvelle carte
        Card new_card(name, cost, description);

        // Vérification des effets
        if (value.contains("effects") && value["effects"].is_array()) {
            for (const auto& effect : value["effects"]) {
                if (!effect.contains("type") || !effect["type"].is_string() ||
                    !effect.contains("parameters")) {
                    throw std::runtime_error("Invalid effect format for card: " + name);
                }

                std::string effect_type = effect["type"];
                // Accès à l'instance de la factory pour créer l'effet
                IEffect* effect_instance = EffectFactory::instance().createEffect(effect_type, effect["parameters"]["amount"]);
                
                if (effect_instance) {
                    new_card.addEffect(effect_instance, effect["parameters"]["target"]);
                } else {
                    throw std::runtime_error("Unknown effect type: " + effect_type);
                }
            }
        }
        // Ajouter la carte au card_map
        card_map.emplace(name, std::move(new_card)); // Utilisation de std::move pour éviter une copie inutile
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

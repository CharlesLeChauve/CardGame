#include "../includes/HUD.hpp"

HUD::HUD(ACharacter& character, sf::Vector2f position) 
    : character(character), position(position),
      hpText(font, "HP: 0", 20),  // ✅ Initialisation correcte
      energyText(font, "Energy: 0", 20) {  // ✅ Initialisation correcte

    if (!font.openFromFile("arial.ttf")) { // SFML 3: `openFromFile`
        throw std::runtime_error("Failed to load font");
    }

    hpText.setFillColor(sf::Color::White);
    hpText.setPosition({position.x, position.y});

    energyText.setFillColor(sf::Color::Yellow);
    energyText.setPosition({position.x, position.y + 30}); // ✅ Correction de la typo
}

void HUD::update() {
    hpText.setString("HP: " + std::to_string(character.getHP()));
    energyText.setString("Energy: " + std::to_string(character.getEnergy()));
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(hpText);
    window.draw(energyText);
}

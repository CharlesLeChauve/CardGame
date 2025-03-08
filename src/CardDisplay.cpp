#include "../includes/CardDisplay.hpp"

CardDisplay::CardDisplay(const Card& card, sf::Vector2f position)
    : font("arial.ttf"), cardShape(), cardText(font, card.getName(), 14) // ✅ Constructeur explicite
{

    cardShape.setSize({120.f, 180.f});
    cardShape.setFillColor(sf::Color::Blue);
    cardShape.setPosition(position);

    cardText.setCharacterSize(14);
    cardText.setFillColor(sf::Color::White);
    cardText.setPosition({position.x + 10.f, position.y + 10.f});
}

void CardDisplay::draw(sf::RenderWindow& window) {
    window.draw(cardShape);
    window.draw(cardText);
}

sf::FloatRect CardDisplay::getGlobalBounds() const {
    return cardShape.getGlobalBounds();
}

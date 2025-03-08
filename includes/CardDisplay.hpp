#pragma once

#include <SFML/Graphics.hpp>
#include "Card.hpp"

class CardDisplay {
    public:
        CardDisplay(const Card& card, sf::Vector2f position);
        
        void draw(sf::RenderWindow& window);
        sf::FloatRect getGlobalBounds() const;
    
    private:
        sf::Text cardText;
        sf::Font font;
        sf::RectangleShape cardShape;
    };

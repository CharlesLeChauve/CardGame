#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include "ACharacter.hpp"

class HUD {
public:
    HUD(ACharacter& character, sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);

private:
    ACharacter& character;
    sf::Text hpText, energyText;
    sf::Font font;
    sf::Vector2f position;
};

#endif

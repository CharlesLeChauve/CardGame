#include "TermDisplay.hpp"

void displayHpEnergy(const ACharacter& character)
{
    std::string color;
    if (character.getHP() <= (character.getMaxHP() / 4))
        color = Color::red;
    else if (character.getHP() <= (character.getMaxHP() / 2))
        color = Color::orange;
    else
        color = Color::green;
    float   ratio = roundf(((float)(character.getHP()) / (float)(character.getMaxHP())) * TERMWIDTH);
    std::cout << color << "|";
    for (int i = 0; i < TERMWIDTH - 2; ++i)
    {
        if (i <= (int)ratio)
            std::cout << "█";
        else
            std::cout << " ";
    }
    std::cout << "|" << Color::reset << std::endl;
    std::cout << "HP : " << character.getHP() << "/" << character.getMaxHP() << " | Energy : ";
    for (int i = 0; i < character.getEnergy(); ++i)
        std::cout << "🔋 ";
    std::cout << std::endl;
}

void    displayBuffs(const ACharacter& character)
{
    if (character.getBuffAmount("fury") > 0)
	    std::cout << "😠:" << character.getBuffAmount("fury") << "   ";
	if (character.getBuffAmount("armor") > 0)
        std::cout << "🛡️:" << character.getBuffAmount("armor") << "   ";
    std::cout << std::endl;
}

void displayCharacterInfo(const ACharacter& character) {
    std::cout << std::setfill('=') << std::setw(TERMWIDTH) << "" << std::endl;
    int padding = (TERMWIDTH - (6 + character.getName().length())) / 2;
    for (int i = 0; i < padding; ++i)
    {
        std::cout << " ";
    }
    std::cout << "Name: " << character.getName();
    for (int i = 0; i < padding; ++i)
    {
        std::cout << " ";
    }
    std::cout << std::endl;
	displayHpEnergy(character);
    displayBuffs(character);
    std::cout << std::setfill('=') << std::setw(TERMWIDTH) << "" << std::endl;
}

void displayGameState(const ACharacter& player1, const ACharacter& player2) {
    std::cout << "\033[2J\033[1;1H"; // Clear the screen
    displayCharacterInfo(player1);
    displayCharacterInfo(player2);
}

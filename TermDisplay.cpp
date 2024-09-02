#include "TermDisplay.hpp"


void displayCharacterInfo(const ACharacter& character) {
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "Name: " << character.getName() << std::endl;

    std::cout << ((character.getHP() > (character.getMaxHP() / 2)) ? Color::green : Color::red) << "HP: " << character.getHP() << "/" << character.getMaxHP() << Color::reset << "  |  " << Color::blue << "Energy: " << character.getEnergy() << Color::reset << std::endl;
	if (character.getBuffAmount("fury") > 0)
	    std::cout << "😠:" << character.getBuffAmount("fury") << "   ";
	if (character.getBuffAmount("armor") > 0)
        std::cout << "🛡️:" << character.getBuffAmount("armor") << "   ";
        std::cout << std::endl;
    std::cout << "Hand Size: " << character.hand.size() << " cards" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
}

void displayGameState(const ACharacter& player1, const ACharacter& player2) {
    std::cout << "\033[2J\033[1;1H"; // Clear the screen
    std::cout << "Game State:\n";
    displayCharacterInfo(player1);
    displayCharacterInfo(player2);
}

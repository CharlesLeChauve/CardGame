#include "TermDisplay.hpp"


void displayCharacterInfo(const ACharacter& character) {
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "Name: " << character.getName() << std::endl;
    std::cout << "HP: " << character.getHP() << "/" << character.getMaxHP() << std::endl;
	if (character.getFury() > 0)
	    std::cout << "😠:" << character.getFury() << std::endl;
	//if (character.getArmor() > 0)
    std::cout << "Hand Size: " << character.hand.size() << " cards" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
}

void displayGameState(const ACharacter& player1, const ACharacter& player2) {
    std::cout << "\033[2J\033[1;1H"; // Clear the screen
    std::cout << "Game State:\n";
    displayCharacterInfo(player1);
    displayCharacterInfo(player2);
}

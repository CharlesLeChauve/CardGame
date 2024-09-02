#pragma once
#include <iostream>
#include <iomanip> // Pour std::setw et std::setfill
#include "ACharacter.hpp"

void displayCharacterInfo(const ACharacter& character);
void displayGameState(const ACharacter& player1, const ACharacter& player2);

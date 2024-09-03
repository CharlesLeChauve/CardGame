#pragma once
#include <iostream>
#include <iomanip> // Pour std::setw et std::setfill
#include "ACharacter.hpp"

#define TERMWIDTH 80

void displayCharacterInfo(const ACharacter& character);
void displayGameState(const ACharacter& player1, const ACharacter& player2);

namespace Color {
    constexpr const char* reset       = "\033[0m";
    constexpr const char* black       = "\033[30m";
    constexpr const char* red         = "\033[31m";
    constexpr const char* green       = "\033[32m";
    constexpr const char* yellow      = "\033[33m";
    constexpr const char* blue        = "\033[34m";
    constexpr const char* magenta     = "\033[35m";
    constexpr const char* cyan        = "\033[36m";
    constexpr const char* white       = "\033[37m";
    constexpr const char* bold_black  = "\033[1m\033[30m";
    constexpr const char* bold_red    = "\033[1m\033[31m";
    constexpr const char* bold_green  = "\033[1m\033[32m";
    constexpr const char* bold_yellow = "\033[1m\033[33m";
    constexpr const char* bold_blue   = "\033[1m\033[34m";
    constexpr const char* bold_magenta = "\033[1m\033[35m";
    constexpr const char* bold_cyan   = "\033[1m\033[36m";
    constexpr const char* bold_white  = "\033[1m\033[37m";
    constexpr const char* orange      = "\033[38;5;208m"; // Orange dans les codes 256 couleurs
    constexpr const char* bold_orange = "\033[1m\033[38;5;208m";
}

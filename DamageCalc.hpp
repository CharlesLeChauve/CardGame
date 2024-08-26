// CombatCalculator.hpp
#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "Card.hpp"

class CombatCalculator {
public:
    // Calcule les dégâts que le joueur inflige à un ennemi
    int calculateDamage(Player& player, Enemy& enemy, Card& attackCard);

    // Autres calculs possibles comme défense, esquive, etc.
    int calculateDefense(Player& player, Enemy& enemy);
};

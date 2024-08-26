#pragma once
#include <iostream>
#include "Enemy.hpp"
#include "Player.hpp"

class GameMediator {
public:
    void playerAttack(Player& player, Enemy& enemy) {
        std::cout << "Player attacks the enemy!" << std::endl;
        enemy.takeDamage(10);  // Logique de dommage ou autre effet
    }

    void enemyAttack(Player& player, Enemy& enemy) {
        std::cout << "Enemy attacks the player!" << std::endl;
        player.takeDamage(5);  // Logique de dommage ou autre effet
    }
};

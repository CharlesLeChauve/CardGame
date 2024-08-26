#pragma once
#include <iostream>
#include "GameMediator.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class GameController {
private:
    GameMediator mediator;  // Le médiateur
    Player player;
    Enemy enemy;

public:
    GameController() : player(&mediator), enemy(&mediator) {}

    void startGame() {
        // Exemple de déroulement de jeu simple
        while (player.getHealth() > 0 && enemy.getHealth() > 0) {
            playerTurn();
            if (enemy.getHealth() > 0) {
                enemyTurn();
            }
        }
        endGame();
    }

private:
    void playerTurn() {
        std::cout << "Player's turn!" << std::endl;
        player.attack(enemy);  // Le player attaque l'ennemi via le mediator
        // On pourrait également gérer la pioche ici si c'est nécessaire
    }

    void enemyTurn() {
        std::cout << "Enemy's turn!" << std::endl;
        enemy.attack(player);  // L'ennemi attaque le joueur via le mediator
    }

    void endGame() {
        if (player.getHealth() > 0) {
            std::cout << "Player wins!" << std::endl;
        } else {
            std::cout << "Enemy wins!" << std::endl;
        }
    }
};

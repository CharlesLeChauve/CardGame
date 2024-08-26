#pragma once
#include <iostream>
#include "GameMediator.hpp"

class Enemy {
private:
    int health;
    GameMediator* mediator;

public:
    Enemy(GameMediator* mediator) : health(50), mediator(mediator) {}

    void attack(Player& player) {
        mediator->enemyAttack(player, *this);
    }

    void takeDamage(int damage) {
        health -= damage;
        std::cout << "Enemy takes " << damage << " damage! Health: " << health << std::endl;
    }

    int getHealth() const { return health; }
};

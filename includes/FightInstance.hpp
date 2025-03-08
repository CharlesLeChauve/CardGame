#pragma once
#include "ACharacter.hpp"
#include "BuffFactory.hpp"
#include <iostream>

class Player;
class Enemy;

class FightInstance
{
private:
	Player& player;
	Enemy& enemy;

	int turnCounter;
    bool fightStarted;
public:
	FightInstance(Player& player, Enemy& enemy);
	~FightInstance();


	void	prepareFighter(ACharacter& fighter);
	void	prepareFighters();
	void	cleanFighters();
	bool	updateFight();
};

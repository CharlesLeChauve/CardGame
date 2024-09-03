#pragma once
#include "ACharacter.hpp"
#include <iostream>

class FightInstance
{
private:
	ACharacter& player;
	ACharacter& enemy;
public:
	FightInstance(ACharacter& player, ACharacter& enemy);
	~FightInstance();

	void	prepareFighter(ACharacter& fighter);
	void	prepareFighters();
	void	cleanFighters();
	void	handleFight();
};

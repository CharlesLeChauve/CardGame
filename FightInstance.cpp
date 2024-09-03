#include "FightInstance.hpp"

FightInstance::FightInstance(ACharacter& player, ACharacter& enemy) : player(player), enemy(enemy)
{
}

FightInstance::~FightInstance()
{
}

void	FightInstance::prepareFighter(ACharacter& fighter)
{
	fighter.deck.shuffle();
}

void	FightInstance::prepareFighters()
{
	prepareFighter(player);
	prepareFighter(enemy);
}

void	FightInstance::cleanFighters()
{
	player.discardBuffs();
}

void	FightInstance::handleFight()
{
	int i = 0;
	this->prepareFighters();
	while (player.getHP() > 0 && enemy.getHP() > 0)
	{
		if (i % 2 == 0)
			player.playTurn(enemy);
		else
			enemy.playTurn(player);
		if (player.getHP() <= 0 || enemy.getHP() <= 0)
		{
			if (enemy.getHP() <= 0)
				std::cout << enemy.getName() << " is Dead." << std::endl;
			else
				std::cout << player.getName() << " is Dead." << std::endl;
			break;
		}
		i++;
	}
	this->cleanFighters();
}
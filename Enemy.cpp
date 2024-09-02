#include "Enemy.hpp"
#include "TermDisplay.hpp"

// Constructeur
Enemy::Enemy(const std::string& name)
    : ACharacter(name, 100, 5)  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
}

// Destructeur
Enemy::~Enemy() = default;

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Enemy::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}

void Enemy::playTurn(ACharacter& opponent)
{
    drawN(3);
    energy += energyCapacity;
	while (this->hand.size() > 0)
	{
		this->printHand();
		this->use(*(this->hand[0]), opponent, 0);
		displayGameState(*this, opponent);
	}
}
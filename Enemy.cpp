#include "Enemy.hpp"
#include "TermDisplay.hpp"

// Constructeur
Enemy::Enemy(const std::string& name)
    : ACharacter(name, 100, name)  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
	setStatsFromTemplate();
}

// Destructeur
Enemy::~Enemy() = default;

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Enemy::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}

void Enemy::setStatsFromTemplate()
{
	std::ifstream file("enemyStats.json");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open baseDecks.json");
    }

    json j;
    file >> j;
    file.close();

	if (!j.contains(this->name))
        throw std::runtime_error("Invalid or missing 'cards' field in JSON.");
	else {
		this->max_hp = j[name]["hp"];
		this->energyCapacity = j[name]["energy"];
		this->hp = j[name]["hp"];
	}

}

void Enemy::playTurn(ACharacter& opponent)
{
    drawN(3);
	buffAdjust();
    energy += energyCapacity;
	while (this->hand.size() > 0 && energy > 0)
	{
		this->printHand();
		this->use(*(this->hand[0]), opponent, 0);
		displayGameState(*this, opponent);
	}
}
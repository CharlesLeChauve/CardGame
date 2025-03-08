#include "../includes/Player.hpp"
#include "../includes/TermDisplay.hpp"

// Constructeur
Player::Player(const std::string& name)
    : ACharacter(name, 100, "basePlayer")  // Initialise ACharacter avec des valeurs spécifiques au joueur
{
}

// Destructeur
Player::~Player() = default;

// Implémentation de la méthode virtuelle pure 'performSpecialAbility'
void Player::performSpecialAbility() {
    // Logique spécifique à la capacité spéciale du joueur
    std::cout << getName() << " performs a special ability!" << std::endl;
}


void Player::startTurn() {
    drawN(5);
    buffAdjust();
    energy += energyCapacity;
    turnState = TurnState::WaitingForInput;
}

void Player::processCardSelection(int cardIndex, ACharacter& opponent) {
    if (turnState != TurnState::WaitingForInput)
        return;
    if (cardIndex < 0 || cardIndex >= static_cast<int>(hand.size())) {
        std::cerr << "Invalid card index." << std::endl;
        return;
    }
    use(*hand[cardIndex], opponent, cardIndex);
    turnState = TurnState::CardSelected;
}

void Player::endTurn() {
    // Termine le tour et nettoie la main
    discardAll();
    turnState = TurnState::TurnEnded;
}



void Player::playTurn(ACharacter& opponent)
{
    std::string i_str;
    int nbr;

    drawN(5);
	buffAdjust();
	energy += energyCapacity;
	while (1)
	{
		displayGameState(*this, opponent);
		this->printHand();
		std::cout << "Choose index or END to end your turn : ";
		std::cin >> i_str;
		if (i_str.compare("END") == 0)
		{
			this->discardAll();
			return ;
		}
		std::stringstream ss(i_str);
		ss >> nbr;
		if (ss.fail())
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
		else if (nbr > this->hand.size() || nbr <= 0)
			std::cout << "Please select a number between 1 && " << this->hand.size() << std::endl;
		else
			this->use(*(this->hand[nbr - 1]), opponent, nbr - 1);
		if (this->getHP() <= 0 || opponent.getHP() <= 0)
			break ;
	}
}

bool Player::isTurnOver() {
	if (this->getHand().empty() || this->getEnergy() == 0) {
		return true;
	}
	return false;
}


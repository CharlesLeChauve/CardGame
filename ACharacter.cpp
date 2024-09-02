#include "ACharacter.hpp"

// Constructeur
ACharacter::ACharacter(const std::string& name, int max_hp, int hand_size)
    : name(name), deck(), max_hp(max_hp), hand_size(hand_size), hp(max_hp), discardPile(), energy(0), energyCapacity(3) {}

// Destructeur
ACharacter::~ACharacter() = default;

// Méthodes communes à tous les personnages
int ACharacter::getHP() const {
    return hp;
}

int ACharacter::getMaxHP() const {
    return max_hp;
}

const std::string& ACharacter::getName() const {
    return name;
}

int ACharacter::getEnergy() const
{
    return energy;
}
int ACharacter::getEnergyCap() const
{
    return energyCapacity;
}

void ACharacter::takeDamage(int damage) {
    int finalDamage = damage;

    if (getBuffAmount("armor"))
    {
        finalDamage -= getBuffAmount("armor");
        addBuff("armor", damage * -1);
    }
    if (finalDamage < 0)
        finalDamage = 0;
    hp -= finalDamage;
    if (hp < 0) hp = 0;
}

void ACharacter::heal(int amount) {
    hp += amount;
    //if (hp > max_hp) hp = max_hp;
}

int ACharacter::getBuffAmount(const std::string& type) const {
    auto it = buffs.find(type);
    if (it == buffs.end()) {
        return 0;
    }
    return it->second;
}

void ACharacter::addBuff(std::string type, int amount)
    {
        if (buffs.find(type) == buffs.end() && amount > 0)
            buffs.emplace(type, amount);
        else
        {
            buffs[type] += amount;
            if (buffs[type] <= 0)
                buffs.erase(type);
        }
    }

// Gestion du deck, de la main et de la pile de défausse
void ACharacter::draw() {
    if (deck.getSize() == 0) {
        if (discardPile.empty()) {
            std::cout << "No more cards to draw..." << std::endl;
            return;
        }
        shuffleDiscard();
    }
    if (hand.size() >= static_cast<size_t>(hand_size))
        discardPile.push_back(deck.draw());
    else
        hand.push_back(deck.draw());
}

void ACharacter::drawN(int n) {
    for (int i = 0; i < n; ++i)
    {
        draw();
    }
}

void ACharacter::printHand() const {
    std::cout << std::left; // Aligner le texte à gauche
    std::cout << "   " << std::setw(4) << "No" << " | "
              << std::setw(20) << "Name" << " | "
              << std::setw(30) << "Description" << " | "
              << std::setw(5) << "Cost" << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << "" << std::endl; // Ligne de séparation
    std::cout << std::setfill(' '); // Remettre le remplissage à l'espace
    int n = 1;
    for (const auto& card : hand) {
        if (card) {
            std::cout << "   " << std::setw(4) << n << " | "
                      << std::setw(20) << card->getName() << " | "
                      << std::setw(30) << card->getDescription() << " | "
                      << std::setw(5) << card->getCost() << std::endl;
            n++;
        } else {
            std::cerr << "Warning: Null card encountered in hand." << std::endl;
        }
    }
};
void ACharacter::use(Card& card, ACharacter& opponent, int index) {
    std::cout << getName() << " uses " << card.getName() << " on " << opponent.getName() << std::endl;
    if (index < hand.size()) {
            if (card.getCost() > energy)
                return ;
            energy -= card.getCost();
            hand[index]->applyEffects(*this, opponent); // Appel de la méthode 'applyEffects' de la carte
            discardPile.push_back(std::move(hand[index]));
            hand.erase(hand.begin() + index);
        } else {
            std::cerr << "Invalid card index" << std::endl;
        }
}

void ACharacter::discardAll()
{
	std::cout << "Shuffling hand into discard pile..." << std::endl;
    while (!hand.empty()) {
        discardPile.push_back(std::move(hand.back()));
        hand.pop_back();
    }
}

void ACharacter::shuffleDiscard() {
    std::cout << "Shuffling discard pile into deck..." << std::endl;
    while (!discardPile.empty()) {
        deck.addCard(std::move(discardPile.back()));
        discardPile.pop_back();
    }
    deck.shuffle();
}

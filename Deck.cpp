#include "Deck.hpp"

// Initialisation du Deck avec des cartes aléatoires
Deck::Deck() {
    Collection& collection = Collection::getInstance();
    cards.push_back(collection.getCard("Healing Potion"));
    cards.push_back(collection.getRandomCard());
    cards.push_back(collection.getRandomCard());
    cards.push_back(collection.getRandomCard());
    cards.push_back(collection.getRandomCard());
    cards.push_back(collection.getCard("Healing Potion"));
}

Deck::~Deck()
{
    // Les pointeurs intelligents libèrent automatiquement la mémoire
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

void Deck::printDeck() const
{
    for (const auto& card : cards)
    {
        std::cout << card->getName() << std::endl;  // Accès via le pointeur
    }
}

// Fonction pour piocher une carte
std::unique_ptr<Card> Deck::draw()
{
    if (cards.empty())
    {
        std::cerr << "Deck is empty!" << std::endl;
        return nullptr;  // Pas de carte à piocher
    }

    // Transférer la propriété de la carte au joueur ou à l'utilisateur
    std::unique_ptr<Card> card = std::move(cards.front());
    cards.erase(cards.begin());  // Supprimer la carte du deck
    return card;
}

int Deck::getSize() const
{
    return cards.size();
}

void Deck::addCard(std::unique_ptr<Card> card)
{
    cards.push_back(std::move(card));  // Transférer la propriété au deck
}

void Deck::removeCard()
{
    if (!cards.empty())
    {
        cards.pop_back();  // Supprime la dernière carte
    }
}

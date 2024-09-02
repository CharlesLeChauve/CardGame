#include "Deck.hpp"
#include "json.hpp"
using json = nlohmann::json;

// Initialisation du Deck avec des cartes aléatoires
Deck::Deck() {
    Collection& collection = Collection::getInstance();
    cards.push_back(collection.getCard("BioStim"));
    cards.push_back(collection.getCard("Punch"));
    cards.push_back(collection.getCard("Testo Shot"));
    cards.push_back(collection.getCard("Punch"));
    cards.push_back(collection.getCard("Punch"));
    cards.push_back(collection.getCard("BioStim"));
    cards.push_back(collection.getCard("Take Cover"));
    cards.push_back(collection.getCard("Take Cover"));
}

Deck::Deck(const std::string& prefab) {
    Collection& collection = Collection::getInstance();
    std::ifstream file("baseDecks.json");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open baseDecks.json");
    }

    json j;
    file >> j;
    file.close();

    if (!j.contains(prefab) || !j[prefab].is_array()) {
        throw std::runtime_error("Invalid or missing 'cards' field in JSON.");
    }
    else
    {
        for (const auto& card : j[prefab])
        {
            cards.push_back(collection.getCard(j[prefab]));
        }
    }
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

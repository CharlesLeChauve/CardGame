#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"
#include "Enemy.hpp"
#include "CardDisplay.hpp"
#include "FightInstance.hpp"
#include "HUD.hpp"

enum class GameState { MENU, COMBAT }; // ✅ Ajout du GameState

class GameWindow {
public:
    GameWindow();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;

    Player player;
    Enemy enemy;
    std::unique_ptr<FightInstance> fight; // ✅ FightInstance uniquement quand nécessaire

    HUD playerHUD;
    HUD enemyHUD;
    std::vector<CardDisplay> playerHandDisplay;

    GameState gameState; // ✅ État du jeu (menu ou combat)
    sf::Text menuText;
    sf::RectangleShape startButton;
    sf::RectangleShape endTurnButton;

    std::unique_ptr<FightInstance> fightInstance;
    sf::Clock combatClock;
    sf::Time combatTurnDelay = sf::seconds(1.0f);

    void processEvents();
    void update();
    void render();
    void startCombat();

    void updatePlayerHandDisplay(); 
};

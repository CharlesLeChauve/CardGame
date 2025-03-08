#include "../includes/GameWindow.hpp"

GameWindow::GameWindow()
    : window(sf::VideoMode({800, 600}), "Card Game"),
      player("Charles"), enemy("Hippie"),
      playerHUD(player, sf::Vector2f(50, 500)),
      enemyHUD(enemy, sf::Vector2f(50, 50)),
      gameState(GameState::MENU), font("arial.ttf"),
      menuText(font, "", 24) {  
          
          std::cout << "GameWindow: Début du constructeur" << std::endl;
          
          std::cout << "Fenêtre SFML créée avec succès, isOpen(): " << window.isOpen() << std::endl;
          
          std::cout << "GameWindow: Font chargée" << std::endl;
          
    menuText.setString("Bienvenue dans CybeRogue\nCliquez pour commencer le combat");
    menuText.setFillColor(sf::Color::White);
    menuText.setPosition({150, 200});
    std::cout << "GameWindow: Texte du menu défini" << std::endl;

    startButton.setSize({200, 50});
    startButton.setFillColor(sf::Color::Green);
    startButton.setPosition({300, 350});
    std::cout << "GameWindow: Bouton du menu défini" << std::endl;
}


void GameWindow::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameWindow::processEvents() {
    if (!window.isOpen()) {  
        std::cerr << "Erreur: La fenêtre SFML est fermée avant pollEvent()" << std::endl;
        return;
    }

    try {
        while (auto eventOpt = window.pollEvent()) {
            sf::Event event = *eventOpt;
            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
            else if (event.is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);
                std::cout << "Clic détecté aux coordonnées : " 
                          << mousePos.x << ", " << mousePos.y << std::endl;

                if (gameState == GameState::MENU && startButton.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Bouton Start cliqué, lancement du combat !" << std::endl;
                    startCombat();
                } else {
                    if (endTurnButton.getGlobalBounds().contains(mousePos)) {
                        player.endTurn();
                        continue;
                    }
                    
                    for (size_t i = 0; i < playerHandDisplay.size(); ++i) {
                        if (playerHandDisplay[i].getGlobalBounds().contains(mousePos)) {
                            player.processCardSelection(static_cast<int>(i), enemy);
                            break;
                        }
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void GameWindow::update() {
    if (gameState == GameState::COMBAT && fightInstance) {
        if (combatClock.getElapsedTime() >= combatTurnDelay) {
            combatClock.restart();
            bool combatContinues = fightInstance->updateFight();
            
            // Mettez à jour le combatLogText si vous le souhaitez
            // combatLogText.setString("A new turn has been executed.");
            
            if (!combatContinues) {
                fightInstance->cleanFighters();
                gameState = GameState::MENU;
            }
        }
    }

    playerHUD.update();
    enemyHUD.update();
}

void GameWindow::render() {
    window.clear();
    
    if (gameState == GameState::MENU) {
        window.draw(menuText);
        window.draw(startButton);
    } else if (gameState == GameState::COMBAT) {
        playerHUD.draw(window);
        enemyHUD.draw(window);
        
        
        for (auto& cardDisplay : playerHandDisplay) {
            cardDisplay.draw(window);
        }
    }
    
    window.display();
}

void GameWindow::startCombat() {
    gameState = GameState::COMBAT;
    fightInstance = std::make_unique<FightInstance>(player, enemy);
}


void GameWindow::updatePlayerHandDisplay() {
    playerHandDisplay.clear();
    const auto& playerHand = player.getHand(); // Par exemple, une méthode qui renvoie la main du joueur
    float cardWidth = 100.f;   // Largeur d'affichage d'une carte
    float spacing   = 10.f;    // Espace entre les cartes
    float startX    = 50.f;    // Position de départ en X
    float posY      = 400.f;   // Position en Y pour l'affichage de la main

    for (size_t i = 0; i < playerHand.size(); ++i) {
        // Déréférencement explicite pour obtenir un const Card&
        const Card& currentCard = *playerHand[i];
        sf::Vector2f cardPosition(startX + i * (cardWidth + spacing), posY);
        CardDisplay cardDisplay(currentCard, cardPosition);
        playerHandDisplay.push_back(cardDisplay);
    }
}
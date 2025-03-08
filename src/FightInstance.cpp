#include "../includes/FightInstance.hpp"
#include "../includes/Enemy.hpp"
#include "../includes/Player.hpp"


FightInstance::FightInstance(Player& player, Enemy& enemy) : player(player), enemy(enemy), turnCounter(0), fightStarted(false) 
{
	this->prepareFighters();
}

FightInstance::~FightInstance()
{
	this->cleanFighters();
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

bool FightInstance::updateFight()
{
    // Si un des combattants est mort, le combat s'arrête
    if (player.getHP() <= 0 || enemy.getHP() <= 0)
        return false;
    
    // Tour du joueur (pair) ou de l'ennemi (impair)
    if (turnCounter % 2 == 0) {
        // Pour le joueur, on suppose qu'on a démarré le tour via startTurn()
        // et qu'une méthode isTurnOver() permet de vérifier que le joueur a terminé son tour
        player.startTurn();
        if (player.isTurnOver()) { // Méthode à implémenter dans Player (ex. état modifié par l'interface)
            // Fin du tour du joueur
            player.endTurn(); // Pour finaliser le tour
            turnCounter++;
        }
    } else {
        // Pour l'ennemi, on peut exécuter une étape non bloquante de son tour
        enemy.playTurn(player); // Méthode non bloquante qui effectue une action d'IA
        // if (enemy.isTurnOver()) { // Vérifie si l'ennemi a terminé son tour
        // }
        enemy.endTurn(); // Finalise son tour
        turnCounter++;
    }
    
    // Vérifier à nouveau si le combat doit s'arrêter après l'action effectuée
    if (player.getHP() <= 0 || enemy.getHP() <= 0)
        return false;
    
    return true;  // Le combat continue
}

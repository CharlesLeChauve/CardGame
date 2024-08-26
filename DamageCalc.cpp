// CombatCalculator.cpp
#include "DamageCalc.hpp"

int CombatCalculator::calculateDamage(Player& player, Enemy& enemy, Card& attackCard) {
    // Exemple basique de calcul
    int baseDamage = attackCard.getAttackPower();
    int playerStrength = player.getStrength();
    int enemyDefense = enemy.getDefense();

    // Formule simple de dégâts : (attaque de base + force du joueur) - défense de l'ennemi
    int damage = (baseDamage + playerStrength) - enemyDefense;

    // Les dégâts ne peuvent pas être négatifs
    if (damage < 0) {
        damage = 0;
    }

    return damage;
}

int CombatCalculator::calculateDefense(Player& player, Enemy& enemy) {
    // Exemple de calcul de défense (ajouter d'autres facteurs si nécessaire)
    return player.getDefense() - enemy.getAttack();
}

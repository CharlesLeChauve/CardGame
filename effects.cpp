#include "effects.hpp"
#include <iostream>

// Définition des fonctions d'effet
std::function<void()> fireball_effect(Enemy *target) {
    return []() {
        std::cout << "Deal 5 damage to an enemy." << std::endl;
        // Logique pour infliger des dégâts
    };
}

std::function<void()> heal_effect(Player *target) {
    return []() {
        std::cout << "Restore 5 health to yourself." << std::endl;
        // Logique pour restaurer la santé
    };
}

std::function<void()> shield_effect(Player *target) {
    return []() {
        std::cout << "Gain 10 armor." << std::endl;
        // Logique pour gagner de l'armure
    };
}

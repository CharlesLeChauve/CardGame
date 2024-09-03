#pragma once
#include "ACharacter.hpp"
#include "Card.hpp"

class DamageCalculator {
public:
    static int calculateDamage(int baseDamage, ACharacter* attacker, ACharacter* target) {
        int finalDamage = baseDamage;

        // Prendre en compte les buffs de l'attaquant (exemple : furie)
        finalDamage += attacker->getBuffAmount("fury");

        // Prendre en compte les buffs de la cible (exemple : armure)
        if (target->getBuffAmount("armor")) {
            finalDamage -= target->getBuffAmount("armor");
            target->addBuff("armor", baseDamage * -1);
        }

        // S'assurer que les dégâts ne sont pas négatifs
        if (finalDamage < 0) {
            finalDamage = 0;
        }

        // Appliquer les dégâts à la cible
        // target->takeDamage(finalDamage);
        // if (target->hp < 0) target->hp = 0;

        // Créer le résultat des dégâts
        return finalDamage;
    }
};

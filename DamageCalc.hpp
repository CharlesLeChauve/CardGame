#pragma once
#include "ACharacter.hpp"
#include "Card.hpp"

class DamageCalculator {
public:
    static int calculateDamage(int baseDamage, ACharacter* attacker, ACharacter* target) {
        int buffDamage = baseDamage;

        // Ici tenter de faire une fonction type getAllAttackBuffs chez ACharacter, puis appliquer tous ceux ayant ce tag ici
        buffDamage += attacker->getBuffAmount("fury");
        int finalDamage = buffDamage;
        if (target->getBuffAmount("armor")) {
            finalDamage -= target->getBuffAmount("armor");
            target->addBuff("armor", buffDamage * -1);
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

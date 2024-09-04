#pragma once
#include "ACharacter.hpp"
#include "IEffect.hpp"
#include <vector>
#include <memory>

class FightEventManager {
public:
    // Méthode pour accéder à l'instance unique du Singleton
    static FightEventManager& getInstance() {
        static FightEventManager instance; // Créé une seule fois et partageé
        return instance;
    }

    // Méthodes pour enregistrer les effets
    void registerDamageTakenEffect(IEffect* effect) {
        damageTakenEffects.push_back(effect);
    }

    void registerHealEffect(IEffect* effect) {
        healEffects.push_back(effect);
    }


	void notifyEvent(ACharacter& notified, ACharacter& opponent)

	
    // Méthodes pour notifier les événements
    // void notifyDamageTaken(ACharacter* character, int damage) {
    //     for (auto& effect : onDamageEffects) {
    //         effect->apply(target, holder);
    //     }
    // }

    // void notifyHeal(ACharacter* character, int amount) {
    //     for (auto& effect : healEffects) {
    //         effect->onHeal(character, amount);
    //     }
    // }

private:
    // Constructeur, opérateur de copie, et destructeur privés pour le Singleton
    FightEventManager() {} 
    FightEventManager(const FightEventManager&) = delete;
    FightEventManager& operator=(const FightEventManager&) = delete;

    std::vector<IEffect *> damageTakenEffects;
    std::vector<IEffect *> healEffects;
    // D'autres listes pour d'autres types d'événements...
};

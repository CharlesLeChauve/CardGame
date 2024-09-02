#include "CEffects.hpp"

void IncreaseFuryEffect::apply(ACharacter* target) const {
    target->increaseFury(amount);
}

std::string IncreaseFuryEffect::getDescription() const {
    return "Increase Fury by " + std::to_string(amount);
}

void    HealEffect::apply(ACharacter* target) const {
    int finalAmount = amount;

    if (target->getHP() + amount > target->getMaxHP())
    {
        finalAmount = target->getMaxHP() - target->getHP();
    }
    target->heal(finalAmount);
}

std::string HealEffect::getDescription() const {
    return ("Heals for " + std::to_string(amount) + " hp.");
}

void   DamageEffect::apply(ACharacter* target) const {
    target->takeDamage(amount);
}

std::string DamageEffect::getDescription() const {
    return ("Inflict " + std::to_string(amount) + " damage.");
}

void IncreaseArmorEffect::apply(ACharacter* target) const {
    target->increaseFury(amount);
}

std::string IncreaseArmorEffect::getDescription() const {
    return "Increase Fury by " + std::to_string(amount);
}
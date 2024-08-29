#include "CEffects.hpp"

void IncreaseFuryEffect::apply(ACharacter* target) const {
    target->increaseFury(amount);
}

std::string IncreaseFuryEffect::getDescription() const {
    return "Increase Fury by " + std::to_string(amount);
}

void    HealEffect::apply(ACharacter* target) const {
    target->heal(amount);
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

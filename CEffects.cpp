#include "CEffects.hpp"

//Fury
void IncreaseFuryEffect::apply(ACharacter* target, ACharacter* holder) const {
    target->addBuff("fury", amount);
}

std::string IncreaseFuryEffect::getDescription() const {
    return "Increase Fury by " + std::to_string(amount);
}


//Heal
void    HealEffect::apply(ACharacter* target, ACharacter* holder) const {
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

//Damage
void   DamageEffect::apply(ACharacter* target, ACharacter* holder) const {
    int finalAmount = DamageCalculator::calculateDamage(amount, holder, target);
    target->takeDamage(finalAmount);
}

std::string DamageEffect::getDescription() const {
    return ("Inflict " + std::to_string(amount) + " damage.");
}

//Armor
void IncreaseArmorEffect::apply(ACharacter* target, ACharacter* holder) const {
    target->addBuff("armor", amount);
}

std::string IncreaseArmorEffect::getDescription() const {
    return "Increase Armor by " + std::to_string(amount);
}

//Energy
void IncreaseEnergyEffect::apply(ACharacter* target, ACharacter* holder) const {
    target->energy += amount;
}

std::string IncreaseEnergyEffect::getDescription() const {
    return "Increase energy by " + std::to_string(amount);
}

//Draw
void DrawEffect::apply(ACharacter* target, ACharacter* holder) const {
    target->drawN(amount);
}

std::string DrawEffect::getDescription() const {
    return "Draw " + std::to_string(amount) + " cards";
}
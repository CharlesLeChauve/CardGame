#pragma once
#include "ACharacter.hpp"
#include <string>

class IEffect;

class IncreaseFuryEffect : public IEffect {
private:
    int amount;
public:
    IncreaseFuryEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target) const override;
    std::string getDescription() const override;
};

class HealEffect : public IEffect {
private:
    int amount;
public:
    HealEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target) const override;
    std::string getDescription() const override;
};

class DamageEffect : public IEffect {
private:
    int amount;
public:
    DamageEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target) const override;
    std::string getDescription() const override;
};


#pragma once
#include "ACharacter.hpp"
#include "DamageCalc.hpp"
#include <string>

class IEffect;

class IncreaseFuryEffect : public IEffect {
private:
    int amount;
public:
    IncreaseFuryEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target, ACharacter* holder) const override;
    std::string getDescription() const override;
};

class HealEffect : public IEffect {
private:
    int amount;
public:
    HealEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target, ACharacter* holder) const override;
    std::string getDescription() const override;
};

class DamageEffect : public IEffect {
private:
    int amount;
public:
    DamageEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target, ACharacter* holder) const override;
    std::string getDescription() const override;
};

class IncreaseArmorEffect : public IEffect {
private:
    int amount;
public:
    IncreaseArmorEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target, ACharacter* holder) const override;
    std::string getDescription() const override;
};

class IncreaseEnergyEffect : public IEffect {
private:
    int amount;
public:
    IncreaseEnergyEffect(int amount) : amount(amount) {}
    void apply(ACharacter* target, ACharacter* holder) const override;
    std::string getDescription() const override;
};
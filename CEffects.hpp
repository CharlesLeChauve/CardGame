#pragma once
#include "IEffect.hpp"
#include "ACharacter.hpp"
#include <string>

class IncreaseFuryEffect : public IEffect {
private:
    int amount;
public:
    IncreaseFuryEffect(int amount) : amount(amount) {}
    void apply(ACharacter& target) const override;
    std::string getDescription() const override;
};

void IncreaseFuryEffect::apply(ACharacter& target) const {
    target.increaseFury(amount);
}

std::string IncreaseFuryEffect::getDescription() const {
    return "Increase Fury by " + std::to_string(amount);
}


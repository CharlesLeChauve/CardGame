#pragma once
// #include "ACharacter.hpp"

class ACharacter;

class IEffect {
public:
    virtual ~IEffect() = default;
    virtual void apply(ACharacter* target, ACharacter* holder) const = 0;
    virtual std::string getDescription() const = 0;
};

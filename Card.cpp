#include "Card.hpp"

Card::Card(std::string name, int cost, std::string description)
    : name(std::move(name)), cost(cost), description(std::move(description)) {}

void Card::addEffect(IEffect* effect, std::string target_type) {
        TargetType target = (target_type == "Holder") ? TargetType::Holder : TargetType::Opponent;
        effects.push_back({effect, target});
    }

void Card::applyEffects(ACharacter& holder, ACharacter& opponent) const {
        for (const auto& targetedEffect : effects) {
            ACharacter* target = (targetedEffect.target == TargetType::Holder) ? &holder : &opponent;
            targetedEffect.effect->apply(target, &holder);
        }
    }

int Card::getCost() const {
    return cost;
}

const std::string& Card::getName() const {
    return name;
}

const std::string& Card::getDescription() const {
    return this->description;
}

// const std::vector<IEffect*>& Card::getEffects() const {
//     return this->effects;
// }
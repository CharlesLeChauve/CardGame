#include "Card.hpp"

Card::Card(std::string name, int cost, std::string description)
    : name(std::move(name)), cost(cost), description(std::move(description)) {}

void Card::addEffect(IEffect* effect, std::string target_type) {
        std::cout << "Type = " << target_type << std::endl;
        TargetType target = (target_type == "Holder") ? TargetType::Holder : TargetType::Opponent;
        std::cout << "Mapped target: " << (target == TargetType::Holder ? "Holder" : "Opponent") << std::endl;
        effects.push_back({effect, target});
    }

void Card::applyEffects(ACharacter& holder, ACharacter& opponent) const {
        for (const auto& targetedEffect : effects) {
            std::cout << "Allo effects" << std::endl;
            ACharacter* target = (targetedEffect.target == TargetType::Holder) ? &holder : &opponent;
            targetedEffect.effect->apply(target);
        }
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
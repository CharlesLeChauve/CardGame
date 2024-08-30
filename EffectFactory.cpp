// EffectFactory.cpp
#include "EffectFactory.hpp"
#include "json.hpp"
#include <iostream>
#include "IEffect.hpp" // Inclure le fichier d'en-tête de IEffect
#include "CEffects.hpp"

class HealEffect;
class IncreaseFuryEffect;
class DamageEffect;

using EffectCreator = std::function<IEffect*(int)>;

using json = nlohmann::json;

class IEffect;

// Definition of the static singleton instance method
EffectFactory& EffectFactory::instance() {
    static EffectFactory factory;
    return factory;
}

// Definition of the method to register a new effect
void EffectFactory::registerEffect(const std::string& type, EffectCreator creator) {
    creators[type] = creator;
}

// Definition of the method to create an effect based on its type
IEffect* EffectFactory::createEffect(const std::string& type, int amount) {
    auto it = creators.find(type);
    if (it != creators.end()) {
	    return it->second(amount);
    }
    return nullptr;
}

void    registerAllEffects()
{
    std::unordered_map<std::string, EffectCreator> effect_map = {
        // Créateur pour un effet de soin
        {"heal", [](int amount) -> IEffect* {
            try {
                return new HealEffect(amount);
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse parameters for HealEffect: " << e.what() << std::endl;
                throw;
            }
        }},
        // Créateur pour un effet d'augmentation de fureur
        {"increase_fury", [](int amount) -> IEffect* {
            try {
                return new IncreaseFuryEffect(amount);
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse parameters for IncreaseFuryEffect: " << e.what() << std::endl;
                throw;
            }
        }},
        {"damage", [](int amount) -> IEffect* {
            try {
                return new DamageEffect(amount);
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse parameters for DamageEffect: " << e.what() << std::endl;
                throw;
            }
        }}
    };

    EffectFactory& factory = EffectFactory::instance();
    for (const auto& [name, creator] : effect_map) {
        factory.registerEffect(name, creator);
    }

}
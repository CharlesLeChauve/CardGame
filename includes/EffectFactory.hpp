// EffectFactory.hpp
#pragma once
#include "json.hpp"

class IEffect;

using json = nlohmann::json;

class EffectFactory {
public:
    using EffectCreator = std::function<IEffect*(const json&)>;

    // Singleton pattern: static method to get the single instance of the factory
    static EffectFactory& instance();

    // Method to register a new effect
    void registerEffect(const std::string& type, EffectCreator creator);

    // Method to create an effect based on its type
    IEffect* createEffect(const std::string& type, int amount);
private:
    // Private constructor for singleton pattern
    EffectFactory() = default;

    // Map to store the effect creators
    std::map<std::string, EffectCreator> creators;
};

void    registerAllEffects();

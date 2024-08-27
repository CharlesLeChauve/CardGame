// EffectFactory.hpp
#pragma once

#include <map>
#include <string>
#include <functional>
#include "IEffect.hpp"

class EffectFactory {
public:
    using EffectCreator = std::function<IEffect*(const std::string&)>;

    static EffectFactory& instance() {
        static EffectFactory factory;
        return factory;
    }

    void registerEffect(const std::string& type, EffectCreator creator) {
        creators[type] = creator;
    }

    IEffect* createEffect(const std::string& type, const std::string& params) const {
        auto it = creators.find(type);
        if (it != creators.end()) {
            return it->second(params);
        }
        return nullptr;
    }

private:
    std::map<std::string, EffectCreator> creators;
};

namespace {
    bool healEffectRegistered = [] {
        EffectFactory::instance().registerEffect("heal", [](const std::string& params) -> IEffect* {
            int healAmount = std::stoi(params); // Convertir les paramètres en integer
            return new HealEffect(healAmount);
        });
        return true;
    }();

    bool increaseFuryEffectRegistered = [] {
        EffectFactory::instance().registerEffect("increase_fury", [](const std::string& params) -> IEffect* {
            int furyAmount = std::stoi(params);
            return new IncreaseFuryEffect(furyAmount);
        });
        return true;
    };
}
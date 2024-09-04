// EffectFactory.cpp
#include "BuffFactory.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include "Buff.hpp"

using BuffCreator = std::function<Buff(int)>;

using json = nlohmann::json;

class IEffect;

// Definition of the static singleton instance me
BuffFactory& BuffFactory::instance() {
    static BuffFactory factory;
    return factory;
}

// Definition of the method to register a new effect
void BuffFactory::registerBuff(const std::string& type, std::vector<std::string> tags) {
    allBuffs.emplace(type, Buff(type, tags));
}

// Definition of the method to create an effect based on its type -- clone()
Buff* BuffFactory::createBuff(const std::string& type, int amount) {
    auto it = allBuffs.find(type);
    if (it != allBuffs.end()) {
		Buff* newBuff = new Buff(it->second);
		newBuff->setAmount(amount);
		std::cout << "Buff created with type = " << newBuff->getType() << ", amount = " << newBuff->getAmount() << std::endl;
	    return (newBuff);
    }
    return nullptr;
}

void    registerAllBuffs()
{
	std::map<std::string, Buff> buff_map;
	std::ifstream file("buffs.json");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open buffs.json");
    }

    json j;
    file >> j;
    file.close();

    BuffFactory& factory = BuffFactory::instance();
	for (const auto& item : j.items())
	{
		factory.instance().registerBuff(item.key(), item.value().get<std::vector<std::string>>());
	}
}
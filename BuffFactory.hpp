#pragma once
#include "json.hpp"

class Buff;

using json = nlohmann::json;

class BuffFactory {
public:
    // Singleton pattern: static method to get the single instance of the factory
    static BuffFactory& instance();

    // Method to register a new effect
    void registerBuff(const std::string& type, std::vector<std::string> tags);

    // Method to create an effect based on its type
    Buff* createBuff(const std::string& type, int amount);
private:
    // Private constructor for singleton pattern
    BuffFactory() = default;

    // Map to store the effect creators
    std::map<std::string, Buff> allBuffs;
};

void    registerAllBuffs();

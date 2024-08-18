#ifndef EFFECTS_HPP
#define EFFECTS_HPP

#include <functional>

// Déclaration des fonctions d'effet
std::function<void()> punch_effect();
std::function<void()> heal_effect();
std::function<void()> stance_effect();

#endif // EFFECTS_HPP

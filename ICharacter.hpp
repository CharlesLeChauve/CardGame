#pragma once
#include <iostream>
#include <string>
#include "Card.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter(void) {};
		virtual std::string const & getName() const = 0;
		virtual void use(Card& card, ICharacter& target) = 0;
};
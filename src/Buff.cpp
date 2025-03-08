#include "../includes/Buff.hpp"

bool Buff::appliesTo(const std::string& tag) const {
	return std::find(tags.begin(), tags.end(), tag) != tags.end();
}

void Buff::applyToDamage(int& damage) const {
	if (type == "fury") {
		damage += amount;
	} else if (type == "armor") {
		damage -= amount;
	}
}

bool Buff::hasTag(const std::string& str) const {
    auto it = std::find(tags.begin(), tags.end(), str);
    return it != tags.end();
}

void Buff::decreaseAmount(int amount)
{
	this->amount -= amount;
}

void Buff::increaseAmount(int amount)
{
	this->amount += amount;
}

Buff::Buff(std::string type, std::vector<std::string> tags) : type(type), amount(0), tags(tags)
{
}

Buff::Buff(const Buff& other) : type(other.type), amount(other.amount), tags(other.tags)
{
}

Buff::~Buff()
{
}

const std::string& Buff::getType() const
{
	return this->type;
}

int Buff::getAmount() const
{
	return this->amount;
}

void Buff::setAmount(int amt)
{
	this->amount = amt;
}

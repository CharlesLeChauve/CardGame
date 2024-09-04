#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Buff
{
private:
	std::string type;
	int 		amount;
	std::vector<std::string> tags;
public:
	Buff(std::string type, std::vector<std::string> tags);
	Buff(const Buff& other);
	~Buff();
	bool hasTag(const std::string& str) const;
	void decreaseAmount(int amount);
	void increaseAmount(int amount);

	const std::string& getType() const;
	int getAmount() const;
	void setAmount(int amt);

};

#pragma once
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(std::string aName, std::string aDescription, int aAmmount);
	virtual ~Potion();
	std::string Use(Hero* aHero);
	virtual std::string getName();
	virtual std::string getDescription();
	virtual std::string toString();

private:
	std::string m_Ammount;
};
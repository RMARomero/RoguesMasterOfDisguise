#pragma once
#include <string>
#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(std::string aName, std::string aDescription);
	virtual ~Potion();
	virtual std::string getName();
	virtual std::string getDescription();

	int Use();
private:
	int m_Ammount;
};


#pragma once
#include <string>
#include "Item.h"
class Torch : public Item
{
public:
	Torch();
	Torch(std::string aName, std::string aDescription, int illumination);
	virtual ~Torch();
	std::string Use(Hero* aHero);
	virtual std::string getName();
	virtual std::string getDescription();
	virtual std::string toString();
	void decreaseIllumination(unsigned int ammount);
	int getIlluminatinCount();

private:
	std::string m_Illumination;
	int m_IlluminationCount;
};


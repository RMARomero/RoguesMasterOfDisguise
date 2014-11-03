#pragma once
#include <string>
#include "Hero.h"

class Hero;
class Item
{
public:
	Item();
	virtual ~Item();
	virtual std::string Use(Hero* aHero) = 0;
	virtual std::string getName();
	virtual std::string getDescription();
protected:
	std::string m_Name;
	std::string m_Description;
};
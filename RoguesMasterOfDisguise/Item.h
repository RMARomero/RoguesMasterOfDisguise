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
	virtual std::string toString();
	
protected:
	std::string m_Name;
	std::string m_Description;
	std::string underscore2space(std::string value);
};
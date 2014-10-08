#pragma once
#include <string>

class Item
{
public:
	Item();
	virtual ~Item();
	virtual std::string getName();
	virtual std::string getDescription();
protected:
	std::string m_Name;
	std::string m_Description;
};


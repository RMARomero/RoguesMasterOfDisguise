#pragma once
#include <string>
class Trap
{
public:
	Trap();
	Trap(std::string aName, std::string aDescription, int trapDamage);
	virtual ~Trap();

	std::string getName();
	std::string getDescription();
	int getTrapDamage();

private:
	std::string m_Name;
	std::string m_Description;
	int m_TrapDamage;
};


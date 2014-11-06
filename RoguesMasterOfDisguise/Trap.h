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

	std::string underscore2space(std::string value);

	bool isTrapTriggered();
	bool isTrapDodged();

	void setTrapTriggered(bool value);
	void setTrapDodged(bool value);

private:
	std::string m_Name;
	std::string m_Description;
	int m_TrapDamage;

	bool m_TrapTriggered;
	bool m_TrapDodged;
};


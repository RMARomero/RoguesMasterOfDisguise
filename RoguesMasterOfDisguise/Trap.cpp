#include "stdafx.h"
#include "Trap.h"

using namespace std;

Trap::Trap()
{
	m_Name = "";
	m_Description = "";
	m_TrapDamage = 5;

	m_TrapDodged = false;
	m_TrapTriggered = false;
}

Trap::Trap(string aName, string aDescription, int trapDamage)
{
	m_Name = underscore2space(aName);
	m_Description = underscore2space(aDescription);
	m_TrapDamage = trapDamage;

	m_TrapDodged = false;
	m_TrapTriggered = false;
}

Trap::~Trap()
{
}

string Trap::getName()
{
	return m_Name;
}

string Trap::getDescription()
{
	return m_Description;
}

int Trap::getTrapDamage()
{
	return m_TrapDamage;
}

std::string Trap::underscore2space(std::string value)
{
	for (std::string::iterator it = value.begin(); it != value.end(); ++it) {
		if (*it == '_') {
			*it = ' ';
		}
	}
	return value;
}

bool Trap::isTrapTriggered()
{
	return m_TrapTriggered;
}

bool Trap::isTrapDodged()
{
	return m_TrapDodged;
}

void Trap::setTrapTriggered(bool value)
{
	m_TrapTriggered = value;
}

void Trap::setTrapDodged(bool value)
{
	m_TrapDodged = value;
}

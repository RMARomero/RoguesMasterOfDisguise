#include "stdafx.h"
#include "Trap.h"

using namespace std;


Trap::Trap()
{
}

Trap::Trap(string aName, string aDescription, int trapDamage)
{
	m_Name = aName;
	m_Description = aDescription;
	m_TrapDamage = trapDamage;
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

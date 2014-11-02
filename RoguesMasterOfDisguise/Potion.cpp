#include "stdafx.h"
#include "Potion.h"

using namespace std;


Potion::Potion()
{
	m_Name = "";
	m_Description = "";
}

Potion::Potion(std::string aName, std::string aDescription, int aAmmount)
{
	m_Name = aName;
	m_Description = aDescription;
	m_Ammount = to_string(aAmmount);
}

Potion::~Potion()
{
}

string Potion::Use()
{
	return m_Ammount;
}

std::string Potion::getName()
{
	return m_Name;
}

std::string Potion::getDescription()
{
	return m_Description;
}
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

string Potion::Use(Hero* aHero)
{
	//int heal = stoi(m_Ammount);
	aHero->Heal(stoi(m_Ammount));
	return "You healed for " + m_Ammount + " ammount of health points";
}

std::string Potion::getName()
{
	return m_Name;
}

std::string Potion::getDescription()
{
	return m_Description;
}
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
	int intAmmount = stoi(m_Ammount);
	aHero->Heal(intAmmount);
	if (intAmmount > 0){
		return "You healed for " + m_Ammount + " ammount of health points";
	} else if (intAmmount == 0){
		return "Your health remains unchanged...";
	}
	else{
		return "\nYou took " + to_string(intAmmount * -1) + " damage...\n";
	}
}

std::string Potion::getName()
{
	return underscore2space(m_Name);
}

std::string Potion::getDescription()
{
	return underscore2space(m_Description);
}

std::string Potion::toString(){
	return "Potion " + m_Name + " " + m_Description + " " + m_Ammount;
}
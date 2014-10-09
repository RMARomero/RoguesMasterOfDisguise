#include "stdafx.h"
#include "Potion.h"


Potion::Potion()
{
	m_Name = "";
	m_Description = "";
}

Potion::Potion(std::string aName, std::string aDescription)
{
	m_Name = aName;
	m_Description = aDescription;
}

Potion::~Potion()
{
}

std::string Potion::getName()
{
	return m_Name;
}

std::string Potion::getDescription()
{
	return m_Description;
}

int Potion::Use()
{
	return m_Ammount;
}
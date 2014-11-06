#include "stdafx.h"
#include "Torch.h"

using namespace std;


Torch::Torch()
{
	m_Name = "";
	m_Description = "";
	m_Illumination = "10";
}

Torch::Torch(string aName, string aDescription, int illumination)
{
	m_Name = aName;
	m_Description = aDescription;
	m_Illumination = to_string(illumination);
	m_IlluminationCount = illumination;
}


Torch::~Torch()
{
}

std::string Torch::Use(Hero* aHero)
{
	//set illumination torch to the player
	aHero->setEquippedItem(this);
	return "You have equipped a torch, which will help illuminate the way for " + m_Illumination + " turns!";
}

std::string Torch::getName()
{
	return underscore2space(m_Name);
}

std::string Torch::getDescription()
{
	return underscore2space(m_Description);
}

void Torch::decreaseIllumination(unsigned int ammount)
{
	if (m_IlluminationCount > 0)
	{
		m_IlluminationCount -= ammount;
		m_Illumination = to_string(m_IlluminationCount);
	}
}

int Torch::getIlluminatinCount()
{
	return m_IlluminationCount;
}

std::string Torch::toString(){
	return "Torch " + m_Name + " " + m_Description + " " + m_Illumination;
}
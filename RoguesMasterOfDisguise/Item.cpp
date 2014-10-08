#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

std::string Item::getName()
{
	return m_Name;
}

std::string Item::getDescription()
{
	return m_Description;
}

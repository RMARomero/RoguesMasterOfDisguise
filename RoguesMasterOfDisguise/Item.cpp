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

std::string Item::toString(){
	return "Item";
}

std::string Item::underscore2space(std::string value){
	for (std::string::iterator it = value.begin(); it != value.end(); ++it) {
		if (*it == '_') {
			*it = ' ';
		}
	}
	return value;
}
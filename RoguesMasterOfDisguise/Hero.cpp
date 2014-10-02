#include "stdafx.h"
#include "Hero.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Hero::Hero()
{
	_name = "";
	_level = 1;
	_xp = 0;
	_maxHealth = 10;
	_currentHealth = 10;
	_attack = 1;
	_defense = 1;
}

void 
Hero::setName(string name){
	_name = name;
}

string 
Hero::getName(){
	return _name;
}

bool 
Hero::IsAlive(){
	return (_currentHealth <= 0) ? true : false;
}

Hero::~Hero()
{
}

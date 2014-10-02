#include "stdafx.h"
#include "Bat.h"

using namespace std;

Bat::Bat(int level)
{
	_name = "Bat";
	_level = level;
	_maxHealth = level;
	_currentHealth = _maxHealth;
	_attack = level * 1;
	_defense = level * 1;
}


Bat::~Bat()
{
}

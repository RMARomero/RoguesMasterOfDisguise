#include "stdafx.h"
#include "Rat.h"

using namespace std;

Rat::Rat(int level)
{
	_name = "Rat";
	_level = level;
	_maxHealth = 1 + level;
	_currentHealth = _maxHealth;
	_attack = level * 1;
	_defense = level * 1;
}

Rat::~Rat()
{

}

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
	_attack = 2;
	_defense = 1;

	_baseAttack = 2;
	_baseDefense = 1;
	_baseHealth = 2;
}

void 
Hero::setName(string name){
	_name = name;
}

string 
Hero::getName(){
	return _name;
}

string Hero::getStats(){
	return _name + "'s stats:"
		+ "\n  Level: " + to_string(_level) 
		+ "\n  Experience: " + to_string(_xp) 
		+ "\n  Health: " + to_string(_currentHealth)
		+ "\n  Attack: " + to_string(_attack) 
		+ "\n  Defense: " + to_string(_defense);
}

int Hero::getCurrentAttack(){
	return _attack;
}

int Hero::getCurrentHealth(){
	return _currentHealth;
}

int
Hero::DoDamage(int attack){
	int damage = ((attack - _defense) > 0) ? (attack - _defense) : 0;
	_currentHealth -= damage;
	return damage;
}

bool 
Hero::IsAlive(){
	return (_currentHealth <= 0) ? false : true;
}


bool Hero::addExperience(int experience){
	_xp += experience;

	int supposed_level = 1 + (0.3 * sqrt(_xp));
	if (_level < supposed_level){
		_level = supposed_level;
		_maxHealth += _baseHealth;
		_currentHealth += _baseHealth;
		_attack += _baseAttack;
		_defense += _baseDefense;
		return true;
	}
	return false;
}
int Hero::getLevel(){
	return _level;
}


Hero::~Hero()
{
}

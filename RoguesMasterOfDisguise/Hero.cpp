#include "stdafx.h"
#include "Hero.h"

#include <string>
#include <sstream>
#include <iostream>

#include "Potion.h"

using namespace std;

Hero::Hero()
{
	//_inventory = new vector<Item*>();
	//test inventory
	_inventory.push_back(new Potion("Mighty Potion", "A very potent potion that heals you for over 9000 hp."));
	_inventory.push_back(new Potion("Mystery Potion", "A mystery potion with unkown effects. Use at your own risk."));
	_inventory.push_back(new Potion("Lesser Potion", "A common potion that heals you for 10 hp."));
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

void Hero::printInventory()
{
	unsigned int slot = 1;
	for (vector<Item*>::iterator it = _inventory.begin(); it != _inventory.end(); it++)
	{
		Item* ptrItem = *it;
		cout << endl;
		cout << slot << "." << ptrItem->getName() << ": " << ptrItem->getDescription() << endl;
		slot++;
	}
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

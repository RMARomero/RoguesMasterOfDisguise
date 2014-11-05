#include "stdafx.h"
#include "Hero.h"

#include <string>
#include <sstream>
#include <iostream>

#include "Potion.h"
#include "Torch.h"

using namespace std;

Hero::Hero()
{
	_inventory = new vector<Item*>();
	_inventory->push_back(new Potion("lol", "foo", 5));
	_equipedItem = nullptr; //remove this here? Give hero always a torch?
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

void Hero::addItemToInventory(Item* item)
{
	_inventory->push_back(item);
}

string Hero::printInventory()
{
	string result = "\n";
	unsigned int slot = 1;
	for (vector<Item*>::iterator it = _inventory->begin(); it != _inventory->end(); it++)
	{
		Item* ptrItem = *it;
		//cout << endl;
		//cout << slot << "." << ptrItem->getName() << ": " << ptrItem->getDescription() << endl;
		result += to_string(slot) + "." + ptrItem->getName() + ": " + ptrItem->getDescription() + "\n";
		slot++;
	}

	return result;
}

Item* Hero::getEquippedItem()
{
	return _equipedItem;
}

void Hero::setEquippedItem(Item* equipment)
{
	_equipedItem = equipment;
}

vector<Item*>* Hero::getInventory()
{
	return _inventory;
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

void Hero::setHealth(int health)
{
	_currentHealth += health;
}

void Hero::Heal(int heal)
{
	_currentHealth += heal;
	if (_currentHealth >= _maxHealth)
		_currentHealth = _maxHealth;
}

int
Hero::DoDamage(int attack){
	int damage = ((attack - _defense) > 0) ? (attack - _defense) : 0;
	_currentHealth -= damage;
	return damage;
}
void Hero::Rest(){
	_currentHealth = _maxHealth;
}

bool 
Hero::IsAlive(){
	return (_currentHealth <= 0) ? false : true;
}


bool Hero::addExperience(int experience){
	_xp += experience;

	int supposed_level = 1 + (int)(0.3 * sqrt(_xp));
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
	for (vector<Item*>::iterator it = _inventory->begin(); it != _inventory->end(); it++)
	{
		delete (*it);
		*it = nullptr;
	}

	/*for (unsigned int i = 0; i < _inventory->size(); i++)
	{
		delete _inventory[i];
		_inventory[i] = nullptr;
	}*/

	delete _inventory;
	_inventory = nullptr;

	delete _equipedItem;
	_equipedItem = nullptr;
}

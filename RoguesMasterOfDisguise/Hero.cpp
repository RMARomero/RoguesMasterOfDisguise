#include "stdafx.h"
#include "Hero.h"

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Potion.h"
#include "Torch.h"

using namespace std;

Hero::Hero()
{
	_inventory = new vector<Item*>();
	_equipedItem = nullptr; 
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

void Hero::doTrapDamage(int damage)
{
	_currentHealth -= damage;
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

	int supposed_level = 1 + (int)(0.1 * sqrt(_xp));
	int levelCap = 100; // Level cap = 100 = (bij 0.3 = 108.900 xp, 0.1 = 980.100 xp);
	if (_level < supposed_level && _level < levelCap){
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

void Hero::Save(){

	const string textfile("heroes/" + _name + ".txt");

	// (1a) Tekst schrijven naar een file
	ofstream output_file(textfile);
	output_file << to_string(_level) + "\n";
	output_file << to_string(_xp) + "\n";
	output_file << to_string(_baseAttack) + "\n";
	output_file << to_string(_baseDefense) + "\n";
	output_file << to_string(_baseHealth) + "\n";
	output_file << to_string(_maxHealth) + "\n";
	output_file << to_string(_currentHealth) + "\n";
	output_file << to_string(_attack) + "\n";
	output_file << to_string(_defense) + "\n";

	for (Item* item : *_inventory){
		output_file << item->toString() + "\n";
	}

}
void Hero::Load(){
	
	ifstream input_file("heroes/" + _name + ".txt");
	string line;
	
	int counter = 0;
	while (getline(input_file, line)) {
		if (line == ""){
			continue;
		}
		switch (counter){
		case 0:
			_level = atoi(line.c_str());
			break;
		case 1:
			_xp = atoi(line.c_str());
			break;
		case 2:
			_baseAttack = atoi(line.c_str());
			break;
		case 3:
			_baseDefense = atoi(line.c_str());
			break;
		case 4:
			_baseHealth = atoi(line.c_str());
			break;
		case 5:
			_maxHealth = atoi(line.c_str());
			break;
		case 6:
			_currentHealth = atoi(line.c_str());
			break;
		case 7:
			_attack = atoi(line.c_str());
			break;
		case 8:
			_defense = atoi(line.c_str());
			break;
		default:
			if (line.substr(0, 6) == "Potion"){
				istringstream iss(line);
				vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
				addItemToInventory(new Potion(tokens.at(1), tokens.at(2), atoi(tokens.at(3).c_str())));
			}
			else if (line.substr(0, 5) == "Torch"){
				istringstream iss(line);
				vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
				addItemToInventory(new Torch(tokens.at(1), tokens.at(2), atoi(tokens.at(3).c_str())));
			}
			break;
		}
		counter++;

	}
}

void Hero::Delete(){
	string file = "heroes/" + _name + ".txt";
	if (std::ifstream(file))
	{
		remove(file.c_str());
	}
}

void Hero::StartUp() {

	if (std::ifstream("heroes/" + _name + ".txt"))
	{
		Load();
	}
	else{
		_inventory->push_back(new Potion("Starter_Potion", "Heals_you_for_a_tiny_bit", 3));//free potion
		Save();
	}

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

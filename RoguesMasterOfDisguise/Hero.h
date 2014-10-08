#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Hero
{
private:
	std::vector<Item>* _inventory;
	std::string _name;
	int _level;
	int _xp;
	int _maxHealth;
	int _currentHealth;
	int _attack;
	int _defense;
public:
	Hero();
	std::vector<Item>* getInventory();
	void setName(std::string name);
	std::string getName();
	bool IsAlive();
	~Hero();
};


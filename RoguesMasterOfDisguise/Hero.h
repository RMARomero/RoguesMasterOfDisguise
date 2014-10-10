#pragma once

#include <vector>
#include "Item.h"

class Hero
{
private:
	std::vector<Item>* _inventory;
	std::string _name;
	int _level;
	int _xp;

	int _baseAttack;
	int _baseDefense;
	int _baseHealth;

	int _maxHealth;
	int _currentHealth;
	int _attack;
	int _defense;
public:
	Hero();
	std::vector<Item>* getInventory();
	void setName(std::string name);
	std::string getName();
	std::string getStats();
	int getCurrentAttack();
	int getCurrentHealth();
	bool addExperience(int experience);
	int getLevel();
	int DoDamage(int attack);
	void Rest();
	bool IsAlive();
	~Hero();
};


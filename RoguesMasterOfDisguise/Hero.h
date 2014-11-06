#pragma once

#include <vector>
#include "Item.h"

class Item;
class Hero
{
private:
	std::vector<Item*>* _inventory;
	Item* _equipedItem;
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
	void addItemToInventory(Item* item);
	std::string printInventory();
	Item* getEquippedItem();
	void setEquippedItem(Item* equipment);
	std::vector<Item*>* getInventory();
	void setName(std::string name);
	std::string getName();
	std::string getStats();
	int getCurrentAttack();
	int getCurrentHealth();
	void doTrapDamage(int damage);
	void setHealth(int health);
	void Heal(int heal);
	bool addExperience(int experience);
	int getLevel();
	int DoDamage(int attack);
	void Rest();
	bool IsAlive();
	~Hero();
};


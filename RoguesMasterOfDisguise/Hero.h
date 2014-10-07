#pragma once

class Hero
{
private:
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
	void setName(std::string name);
	std::string getName();
	std::string getStats();
	int getCurrentAttack();
	int getCurrentHealth();
	bool addExperience(int experience);
	int getLevel();
	int DoDamage(int attack);
	bool IsAlive();
	~Hero();
};


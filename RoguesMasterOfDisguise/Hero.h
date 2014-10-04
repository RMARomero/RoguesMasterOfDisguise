#pragma once

class Hero
{
private:
	std::string _name;
	int _level;
	int _xp;
	int _maxHealth;
	int _currentHealth;
	int _attack;
	int _defense;
public:
	Hero();
	void setName(std::string name);
	std::string getName();
	bool IsAlive();
	~Hero();
};


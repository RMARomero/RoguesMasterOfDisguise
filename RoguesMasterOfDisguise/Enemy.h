#pragma once
#include <string>

class Enemy
{
protected:
	std::string _name;
	int _level;
	int _maxHealth;
	int _currentHealth;
	int _attack;
	int _defense;
public:
	Enemy();
	virtual std::string GetName();
	virtual int GetLevel();
	virtual std::string GetEnemyInfo();
	virtual std::string GetBattleStatus();
	virtual int getCurrentAttack();
	virtual void DoDamage(int attack);
	virtual ~Enemy();
};


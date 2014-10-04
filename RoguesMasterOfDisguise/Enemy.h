#pragma once

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
	Enemy(std::string name, int level);
	std::string GetName();
	int GetLevel();
	std::string GetEnemyInfo();
	std::string GetBattleStatus();
	int getCurrentAttack();
	void DoDamage(int attack);
	~Enemy();
};


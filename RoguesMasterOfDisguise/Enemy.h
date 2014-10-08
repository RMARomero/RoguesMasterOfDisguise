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
	int _experienceOnKill;
public:
	Enemy(std::string name, int level, int healthPerLevel, int attackPerLevel, int defensePerLevel, int experienceOnKill);
	std::string GetName();
	int GetLevel();
	std::string GetEnemyInfo();
	std::string GetBattleStatus();
	int getCurrentAttack();
	int DoDamage(int attack);
	int GetExperienceOnKill();
	bool IsAlive();
	Enemy* Clone(int level);
	~Enemy();
};


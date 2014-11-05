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
	int _maxDungeonLevel;
	int _minDungeonLevel;
public:
	Enemy(std::string name, int level, int healthPerLevel, int attackPerLevel, int defensePerLevel, int experienceOnKill, int minDungeonLevel, int maxDungeonLevel);
	std::string GetName();
	int GetLevel();
	std::string GetEnemyInfo();
	std::string GetBattleStatus();
	int getCurrentAttack();
	int DoDamage(int attack);
	int GetExperienceOnKill();
	bool IsAlive();

	int getMaxDungeonLevel();
	int getMinDungeonLevel();

	Enemy* Clone(int level);
	~Enemy();
};


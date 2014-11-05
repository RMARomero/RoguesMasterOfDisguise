#include "stdafx.h"
#include "Enemy.h"

using namespace std;


Enemy::Enemy(string name, int level, int healthPerLevel, int attackPerLevel, int defensePerLevel, int experienceOnKill, int minDungeonLevel, int maxDungeonLevel){
	_name = name;
	_level = level;
	_maxHealth = level * healthPerLevel;
	_currentHealth = _maxHealth;
	_attack = level * attackPerLevel;
	_defense = level * defensePerLevel;
	_experienceOnKill = experienceOnKill * level;
	_minDungeonLevel = minDungeonLevel;
	_maxDungeonLevel = maxDungeonLevel;
}
Enemy::~Enemy(){

}



string
Enemy::GetName(){
	return _name;
}

int
Enemy::GetLevel(){
	return _level;
}

string
Enemy::GetBattleStatus(){
	string result = "healthy";
	float percentageHealth = (float)_currentHealth / (float)_maxHealth * 100;
	if (percentageHealth <= 0){
		string result = "dead";
	}
	if (percentageHealth < 25){
		string result = "almost dead";
	}
	else if (percentageHealth < 50){
		string result = "damaged";
	}
	else if (percentageHealth < 75){
		string result = "slightly damaged";
	}
	return GetName() + " is " + result + ".";
}

int
Enemy::getCurrentAttack(){
	return _attack;
}

int
Enemy::DoDamage(int attack){
	int damage = ((attack - _defense) > 0) ? (attack - _defense) : 0;
	_currentHealth -= damage;
	return damage;
}

string
Enemy::GetEnemyInfo(){
	return "A wild " + GetName() + " appears!";
}

bool
Enemy::IsAlive(){
	return (_currentHealth <= 0) ? false : true;
}

int Enemy::GetExperienceOnKill(){
	return _experienceOnKill;
}

int Enemy::getMaxDungeonLevel(){
	return _maxDungeonLevel;
}
int Enemy::getMinDungeonLevel(){
	return _minDungeonLevel;
}

Enemy* Enemy::Clone(int level){
	return new Enemy(_name, level, _maxHealth, _attack, _defense, _experienceOnKill, _minDungeonLevel, _maxDungeonLevel);
}
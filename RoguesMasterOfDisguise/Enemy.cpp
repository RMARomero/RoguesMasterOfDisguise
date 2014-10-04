#include "stdafx.h"
#include "Enemy.h"

using namespace std;


Enemy::Enemy(string name, int level){
	_name = name;
	_level = level;
	_maxHealth = level;
	_currentHealth = _maxHealth;
	_attack = level * 1;
	_defense = level * 1;
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

void
Enemy::DoDamage(int attack){
	_currentHealth -= ((_defense - attack) > 0) ? 0 : (_defense - attack);
}

string
Enemy::GetEnemyInfo(){
	return "A wild " + GetName() + " appears!";
}

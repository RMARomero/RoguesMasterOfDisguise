#pragma once
#include <vector>
#include "RandomValue.h"
#include "Enemy.h"
#include "Potion.h"
#include "Torch.h"
#include "Trap.h"

class Factory
{
private:
	Factory();
	static Factory* _instance;

	RandomValue* _random;
	std::vector<std::string>* randomRoomSizeValues;
	std::vector<std::string>* randomRoomConditionValues;
	std::vector<std::string>* randomRoomDecorationValues;
	std::vector<std::string>* randomRoomLightningValues;

	std::vector<std::string>* potionNames;
	std::vector<std::string>* potionDescriptions;
	std::vector<std::string>* potionHeals;

	std::vector<std::string>* torchNames;
	std::vector<std::string>* torchDescription;
	std::vector<std::string>* torchValues;

	std::vector<std::string>* trapNames;
	std::vector<std::string>* trapDescriptions;
	std::vector<std::string>* trapDamages;
	
	std::vector<Enemy*>* UniqueEnemies;
	std::vector<Enemy*>* UniqueBosses;

	void fillRoomVectors();
	void fillEnemyVector();
	void fillItemVector();
	void fillTrapVector();

public:
	static Factory* getInstance();
	std::string getRandomRoomValue();
	Enemy* getRandomEnemy(int level);
	Enemy* getRandomBoss();
	Item* getRandomItem();
	Trap* getRandomTrap();
	~Factory();
};


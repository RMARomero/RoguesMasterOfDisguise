#pragma once
#include <vector>
#include "RandomValue.h"
#include "Enemy.h"

class ReadTextFile
{
private:
	ReadTextFile();
	static ReadTextFile* _instance;

	RandomValue* _random;
	std::vector<std::string> randomRoomSizeValues;
	std::vector<std::string> randomRoomConditionValues;
	std::vector<std::string> randomRoomDecorationValues;
	std::vector<std::string> randomRoomLightningValues;

	std::vector<Enemy*> UniqueEnemies;

	void fillRoomVectors();
	void fillEnemyVector();
public:
	static ReadTextFile* getInstance();
	std::string getRandomRoomValue();
	Enemy* getRandomEnemy(int level);
	~ReadTextFile();
};


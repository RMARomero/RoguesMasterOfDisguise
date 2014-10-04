#pragma once
#include <vector>
#include "RandomValue.h"

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

	void fillRoomVectors();
	void fillEnemyVectors();
public:
	static ReadTextFile* getInstance();
	std::string getRandomRoomValue();
	std::string getRandomEnemyValues();
	~ReadTextFile();
};


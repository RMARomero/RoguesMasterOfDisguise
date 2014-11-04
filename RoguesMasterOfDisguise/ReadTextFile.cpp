#include "stdafx.h"
#include <fstream>
#include "ReadTextFile.h"

using namespace std;

ReadTextFile* ReadTextFile::_instance = nullptr;

ReadTextFile::ReadTextFile()
{
	randomRoomSizeValues = new vector<string>();
	randomRoomConditionValues = new vector<string>();
	randomRoomDecorationValues = new vector<string>();
	randomRoomLightningValues = new vector<string>();

	potionNames = new vector<string>();
	potionDescriptions = new vector<string>();
	potionHeals = new vector<string>();

	torchNames = new vector<string>();
	torchValues = new vector<string>();

	fillRoomVectors();
	fillEnemyVector();
	fillItemVector();
}

ReadTextFile*
ReadTextFile::getInstance() {
	if (_instance == nullptr) {
		_instance = new ReadTextFile;
	}
	return _instance;
}

ReadTextFile::~ReadTextFile()
{
	//delete _instance;

	//delete _enemies;
	for (unsigned int i = 0; i < UniqueEnemies.size(); i++){
		delete UniqueEnemies.at(i);
	}
	delete randomRoomSizeValues;
	delete randomRoomConditionValues;
	delete randomRoomDecorationValues;
	delete randomRoomLightningValues;

	delete potionNames;
	potionNames = nullptr;
	delete potionDescriptions;
	potionDescriptions = nullptr;
	delete potionHeals;
	potionHeals = nullptr;
	delete torchNames;
	torchNames = nullptr;
	delete torchValues;
	torchValues = nullptr;
}

void ReadTextFile::fillRoomVectors(){
	const string randomRoomValues("RandomRoomValues.txt");

	ifstream input_file(randomRoomValues); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector<string> *currentVector = randomRoomSizeValues;

	while (getline(input_file, line)) {
		if (line == ""){
		}
		else if (line == "Size:"){
			currentVector = randomRoomSizeValues;
		}
		else if (line == "Condition:"){
			currentVector = randomRoomConditionValues;
		}
		else if (line == "Decoration:"){
			currentVector = randomRoomDecorationValues;
		}
		else if (line == "Lightning:"){
			currentVector = randomRoomLightningValues;
		}
		else{
			currentVector->push_back(line);
		}
	}
}

void ReadTextFile::fillEnemyVector(){
	const string randomEnemyValues("RandomEnemyValues.txt");
	// variabelen waarin de ingelezen waarden terecht komen
	string line;
	string name = "";
	int healthPerLevel = 0;
	int attackPerLevel = 0;
	int defensePerLevel = 0;
	int experienceOnKill = 0;
	// input file stream, opent textfile voor lezen
	ifstream input_file(randomEnemyValues);

	while (input_file >> name >> healthPerLevel >> attackPerLevel >> defensePerLevel >> experienceOnKill) {
		string result = name + to_string(healthPerLevel) + to_string(attackPerLevel) + to_string(defensePerLevel) + to_string(experienceOnKill);
		UniqueEnemies.push_back(new Enemy(name, 1, healthPerLevel, attackPerLevel, defensePerLevel, experienceOnKill));
	}
	//Enemy* enemy = ;

}
 
void ReadTextFile::fillItemVector() {
	const string randomItemValues("RandomItemValues.txt");
	string line;

	ifstream input_file(randomItemValues);

	vector<string>* currentVector = potionNames;

	while (getline(input_file, line)) 
	{
		if (line == "")
		{
		}
		else if (line == "PotionName:")
		{
			currentVector = potionNames;
		}
		else if (line == "PotionDescription:")
		{
			currentVector = potionDescriptions;
		}
		else if (line == "PotionHeal:")
		{
			currentVector = potionHeals;
		}
		else if (line == "TorchName:")
		{
			currentVector = torchNames;
		}
		else if (line == "TorchValue:")
		{
			currentVector = torchValues;
		}
		else
		{
			currentVector->push_back(line);
		}
	}
}

string ReadTextFile::getRandomRoomValue(){

	int chance = _random->getRandom(0, randomRoomSizeValues->size());
	string roomSize = randomRoomSizeValues->at(chance);

	chance = _random->getRandom(0, randomRoomConditionValues->size());
	string roomCondition = randomRoomConditionValues->at(chance);

	chance = _random->getRandom(0, randomRoomDecorationValues->size());
	string roomDecoration = randomRoomDecorationValues->at(chance);

	chance = _random->getRandom(0, randomRoomLightningValues->size());
	string roomLightning = randomRoomLightningValues->at(chance);

	return roomSize + " " + roomCondition + " " + roomDecoration + " " + roomLightning;
}

Enemy* ReadTextFile::getRandomEnemy(int level){
	int chance = _random->getRandom(0, UniqueEnemies.size());
	return UniqueEnemies.at(chance)->Clone(level);
}

Item* ReadTextFile::getRandomItem()
{
	int itemRandom = _random->getRandom(0, 3);

	if (itemRandom == 0)
	{
		//do potions
		int chance = _random->getRandom(0, potionNames->size());
		string potionName = potionNames->at(chance);

		string potionDescription = potionDescriptions->at(chance);

		string potionHeal = potionHeals->at(chance);

		Potion* potion = new Potion(potionName, potionDescription, atoi(potionHeal.c_str()));

		return potion;
	}
	else if (itemRandom == 1)
	{
		//do torch
		int chance = _random->getRandom(0, torchNames->size());
		string torchName = torchNames->at(chance);

		string torchValue = torchValues->at(chance);

		Torch* torch = new Torch(torchName, "A lightsource", atoi(torchValue.c_str()));

		return torch;
	}
	else
		return nullptr;
}
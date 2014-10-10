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
	fillRoomVectors();
	fillEnemyVector();
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
	for (int i = 0; i < UniqueEnemies.size(); i++){
		delete UniqueEnemies.at(i);
	}
	delete randomRoomSizeValues;
	delete randomRoomConditionValues;
	delete randomRoomDecorationValues;
	delete randomRoomLightningValues;
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
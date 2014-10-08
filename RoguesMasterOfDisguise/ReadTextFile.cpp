#include "stdafx.h"
#include <fstream>
#include "ReadTextFile.h"

using namespace std;

ReadTextFile* ReadTextFile::_instance = nullptr;

ReadTextFile::ReadTextFile()
{
	_random = RandomValue::getInstance();
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
	delete _instance;
}

void ReadTextFile::fillRoomVectors(){
	const string randomRoomValues("RandomRoomValues.txt");
	const string randomEnemyValues("RandomEnemyValues.txt");

	ifstream input_file(randomRoomValues); // stack-based file object; deze constructie opent de file voor lezen
	string line;

	vector<string> *currentVector = &randomRoomSizeValues;

	while (getline(input_file, line)) {
		if (line == ""){
		}
		else if (line == "Size:"){
			currentVector = &randomRoomSizeValues;
		}
		else if (line == "Condition:"){
			currentVector = &randomRoomConditionValues;
		}
		else if (line == "Decoration:"){
			currentVector = &randomRoomDecorationValues;
		}
		else if (line == "Lightning:"){
			currentVector = &randomRoomLightningValues;
		}
		else{
			currentVector->push_back(line);
		}
	}
}

void ReadTextFile::fillEnemyVectors(){

}

string ReadTextFile::getRandomRoomValue(){

	int chance = _random->getRandom(0, randomRoomSizeValues.size());
	string roomSize = randomRoomSizeValues.at(chance);

	chance = _random->getRandom(0, randomRoomConditionValues.size());
	string roomCondition = randomRoomConditionValues.at(chance);

	chance = _random->getRandom(0, randomRoomDecorationValues.size());
	string roomDecoration = randomRoomDecorationValues.at(chance);

	chance = _random->getRandom(0, randomRoomLightningValues.size());
	string roomLightning = randomRoomLightningValues.at(chance);

	return roomSize + " " + roomCondition + " " + roomDecoration + " " + roomLightning;
}
string ReadTextFile::getRandomEnemyValues(){
	return "";
}
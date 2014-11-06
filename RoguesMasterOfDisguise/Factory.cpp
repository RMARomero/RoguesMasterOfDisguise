#include "stdafx.h"
#include <fstream>
#include "Factory.h"
#include <sstream>

using namespace std;

Factory* Factory::_instance = nullptr;

Factory::Factory()
{
	randomRoomSizeValues = new vector<string>();
	randomRoomConditionValues = new vector<string>();
	randomRoomDecorationValues = new vector<string>();
	randomRoomLightningValues = new vector<string>();

	potionNames = new vector<string>();
	potionDescriptions = new vector<string>();
	potionHeals = new vector<string>();

	torchNames = new vector<string>();
	torchDescription = new vector<string>();
	torchValues = new vector<string>();

	trapNames = new vector<string>();
	trapDescriptions = new vector<string>();
	trapDamages = new vector<string>();

	UniqueEnemies = new vector<Enemy*>();
	UniqueBosses = new vector<Enemy*>();

	fillRoomVectors();
	fillEnemyVector();
	fillItemVector();
	fillTrapVector();
}

Factory*
Factory::getInstance() {
	if (_instance == nullptr) {
		_instance = new Factory;
	}
	return _instance;
}

Factory::~Factory()
{
	//delete _instance;

	//delete _enemies;
	for (unsigned int i = 0; i < UniqueEnemies->size(); i++){
		delete UniqueEnemies->at(i);
	}
	delete UniqueEnemies;
	for (unsigned int i = 0; i < UniqueBosses->size(); i++){
		delete UniqueBosses->at(i);
	}
	delete UniqueBosses;

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
	delete torchDescription;
	torchDescription = nullptr;
	delete torchValues;
	torchValues = nullptr;

	delete trapNames;
	trapNames = nullptr;
	delete trapDescriptions;
	trapDescriptions = nullptr;
	delete trapDamages;
	trapDamages = nullptr;
}

void Factory::fillRoomVectors(){
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

void Factory::fillEnemyVector(){
	const string randomEnemyValues("RandomEnemyValues.txt");
	// variabelen waarin de ingelezen waarden terecht komen
	string line;
	string name = "";
	int healthPerLevel = 0;
	int attackPerLevel = 0;
	int defensePerLevel = 0;
	int experienceOnKill = 0;
	int minDungeonLevel = 0; //Minimum dungeon level
	int maxDungeonLevel = 0; //Minimum dungeon level

	ifstream input_file(randomEnemyValues);


	vector<Enemy*>* currentVector = UniqueEnemies;

	while (getline(input_file, line)){
		if ((line[0] == '/') &&
			(line[1] == '/')){
			continue;
		}

		if (line == ""){

		}
		else if (line == "Normal:"){
			currentVector = UniqueEnemies;
		}
		else if (line == "Boss:"){
			currentVector = UniqueBosses;
		}
		else{
			istringstream iss(line);
			vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
			name = tokens.at(0);
			healthPerLevel = atoi(tokens.at(1).c_str());
			attackPerLevel = atoi(tokens.at(2).c_str());
			defensePerLevel = atoi(tokens.at(3).c_str());
			experienceOnKill = atoi(tokens.at(4).c_str());
			minDungeonLevel = atoi(tokens.at(5).c_str());
			maxDungeonLevel = atoi(tokens.at(6).c_str());

			currentVector->push_back(new Enemy(name, 1, healthPerLevel, attackPerLevel, defensePerLevel, experienceOnKill, minDungeonLevel, maxDungeonLevel));
		}
	}



}

void Factory::fillItemVector() {
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
		else if (line == "TorchDescription:")
		{
			currentVector = torchDescription;
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

void Factory::fillTrapVector()
{
	const string randomTrapValues("RandomTrapValues.txt");
	string line;

	ifstream input_file(randomTrapValues);

	vector<string>* currentVector = trapNames;

	while (getline(input_file, line))
	{
		if (line == "")
		{
		}
		else if (line == "TrapName:")
		{
			currentVector = trapNames;
		}
		else if (line == "TrapDescription:")
		{
			currentVector = trapDescriptions;
		}
		else if (line == "TrapDamage:")
		{
			currentVector = trapDamages;
		}
		else
		{
			currentVector->push_back(line);
		}
	}
}

string Factory::getRandomRoomValue(){

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

Enemy* Factory::getRandomEnemy(int level){
	vector<Enemy*> tempEnemyList;

	for (Enemy* enemy : *UniqueEnemies){
		if (enemy->getMinDungeonLevel() <= level && enemy->getMaxDungeonLevel() >= level){
			tempEnemyList.push_back(enemy);
		}
	}

	int chance = _random->getRandom(0, tempEnemyList.size());
	return tempEnemyList.at(chance)->Clone(level);
}

Enemy* Factory::getRandomBoss(){
	int chance = _random->getRandom(0, UniqueBosses->size());
	return UniqueBosses->at(chance)->Clone(11); /* 11, since they should be stronger then lvl 10 mobs */
}

Item* Factory::getRandomItem()
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

		string torch_Description = torchDescription->at(chance);

		string torchValue = torchValues->at(chance);


		Torch* torch = new Torch(torchName, torch_Description, atoi(torchValue.c_str()));

		return torch;
	}
	else
		return nullptr;
}

Trap* Factory::getRandomTrap()
{
	int findTrapChance = 25;
	int trapRandom = _random->getRandom(1, 100);

	if (trapRandom <= 25)
	{
		//do traps
		int chance = _random->getRandom(0, trapNames->size());
		string trapName = trapNames->at(chance);

		string trapDescription = trapDescriptions->at(chance);

		string trapDamage = trapDamages->at(chance);

		Trap* trap = new Trap(trapName, trapDescription, atoi(trapDamage.c_str()));

		return trap;
	}
	else
		return nullptr;
}
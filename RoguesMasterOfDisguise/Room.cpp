#include "stdafx.h"
#include "Room.h"
#include "RandomValue.h"
#include "ReadTextFile.h"

using namespace std;

Room::Room(int room_lvl)
{
	_visited = false;
	_stairsUp = false;
	_stairsDown = false;

	_room_level = room_lvl;
	_random = RandomValue::getInstance();

	_roomDescription = ReadTextFile::getInstance()->getRandomRoomValue();

	_roomNorth = nullptr;
	_roomEast = nullptr;
	_roomSouth = nullptr;
	_roomWest = nullptr;

	spawnEnemies();
}

string 
Room::toString(){
	string result = "Description: ";

	result += getVisitedInformation();
	result += _roomDescription;
	result += getExitInformation();
	result += getEnemyInformation();
	result += getChoiceInformation();

	setVisited();
	return result;
}

void 
Room::setRoomNorth(Room* room){
	_roomNorth = room;
}

void 
Room::setRoomEast(Room* room){
	_roomEast = room;
}
void 
Room::setRoomSouth(Room* room){
	_roomSouth = room;
}

void 
Room::setRoomWest(Room* room){
	_roomWest = room;
}

Room* 
Room::getRoomNorth(){
	return _roomNorth;
}

Room* 
Room::getRoomEast(){
	return _roomEast;
}

Room* 
Room::getRoomSouth(){
	return _roomSouth;
}

Room* 
Room::getRoomWest(){
	return _roomWest;
}


string 
Room::getExitInformation(){
	string result = "\n\nExits: ";
	vector<string> doorWays;

	if (_roomNorth != nullptr || _roomEast != nullptr || _roomSouth != nullptr || _roomWest != nullptr){
		result += "There is a room to the ";
	}
	if (_roomNorth != nullptr){
		doorWays.push_back("north");
	}
	if (_roomEast != nullptr){
		doorWays.push_back("east");
	}
	if (_roomSouth != nullptr){
		doorWays.push_back("south");
	}
	if (_roomWest != nullptr){
		doorWays.push_back("west");
	}

	int roomCounter = 0;
	for (string doorWay : doorWays){
		if (roomCounter == (doorWays.size() - 1) && roomCounter != 0){
			result += " and " + doorWay;
		}
		else if (roomCounter > 0){
			result += ", "+doorWay;
		}
		else{
			result += doorWay;
		}
		roomCounter++;
	}

	if (roomCounter > 0){
		result += ". ";
	}

	if (getStairsUp()){
		result += "There are some stairs in here, leading up. ";
	}
	if (getStairsDown()){
		result += "There are some stairs in here, leading down. ";
	}
	if (getExit()){
		result += "The exit is here aswell.";
	}

	return result;
}
string
Room::getEnemyInformation(){
	string result = "";
	if (_enemies.size() <= 0){
		return result;
	}
	result += "\n\nPresence: ";
	for (Enemy* enemy : _enemies) {
		result +=  "\n"+enemy->GetEnemyInfo();
	}

	return result;

}

string 
Room::getVisitedInformation(){
	if (_visited){
		return "You have been here before. ";
	}
	return "";
}

string 
Room::getChoiceInformation(){
	string result = "\n\n{";
	if (_enemies.size() > 0){
		result += "fight, ";
		result += "flee, ";
	}
	else{
		result += "move, ";
	}

	result += "map, ";
	result += "inventory, ";

	if (getStairsUp() || getStairsDown()){
		result += "stairs, ";
	}
	if (getExit()){
		result += "exit, ";
	}

	//Fix string:
	if (result.size() > 1){
		result.resize(result.size() - 2);
	}
	result += "}";
	return result;
}

void 
Room::spawnEnemies(){
	int chance = _random->getRandom(0, 100);
	if (chance > 25){
		return;
	}
	chance = _random->getRandom(0, 100);
	int amountOfEnemies;
	if (chance < 2){
		amountOfEnemies = 5; //3% chance
	}
	else if (chance < 9){
		amountOfEnemies = 4; //6% chance
	}
	else if (chance < 19){
		amountOfEnemies = 3; //10% chance
	}
	else if (chance < 49){
		amountOfEnemies = 2; //30% chance
	}
	else{
		amountOfEnemies = 1; //50% chance
	}

	for (int i = 0; i < amountOfEnemies; i++){
		_enemies.push_back(new Enemy("rat", _room_level));
	}

}



void 
Room::setVisited(){
	_visited = true;
}

bool 
Room::getVisited(){
	return _visited;
}

void 
Room::enableStairsUp(){
	_stairsUp = true;
}

void 
Room::enableStairsDown(){
	_stairsDown = true;
}

void 
Room::enableExit(){
	_exit = true;
}

bool 
Room::getStairsUp(){
	return _stairsUp;
}

bool 
Room::getStairsDown(){
	return _stairsDown;
}

bool 
Room::getExit(){
	return _exit;
}

string 
Room::getMoveChoices(){

	string result = "{";
	if (_roomNorth != nullptr){
		result += "north, ";
	}
	if (_roomEast != nullptr){
		result += "east, ";
	}
	if (_roomSouth != nullptr){
		result += "south, ";
	}
	if (_roomWest != nullptr){
		result += "west, ";
	}
	
	if (result.size() > 1){
		result.resize(result.size() - 2);
	}
	else{
		result += "You are trapped!";
	}
	result += "}";
	return result;
}

void 
Room::enableBoss(){
	_boss = true;
}

bool 
Room::getBoss(){
	return _boss;
}

Room::~Room()
{
	for (Enemy* enemy : _enemies) {
		delete enemy;
	}
}

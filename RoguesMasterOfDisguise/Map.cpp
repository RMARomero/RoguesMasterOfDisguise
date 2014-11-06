#include "stdafx.h"
#include "Map.h"
#include "RandomValue.h"

#include <iostream>
#include <map>
#include <set>

using namespace std;

Map::Map(){

}

Map::Map(int map_level, int max_map_level, int max_length)
{

	_random = RandomValue::getInstance();
	_map_level = map_level;
	_max_map_level = max_map_level;

	int current_length = 0;
	newRoomChance = 40;

	int x = _random->getRandom(0, (matrixWidth - 1));
	int y = _random->getRandom(0, (matrixHeight - 1));
	_startingRoom = new Room(_map_level);
	matrix[x][y] = _startingRoom;
	CreateRoom(_startingRoom, x, y, true, current_length, max_length);
	if (map_level == 1){ // if map_level equals first room
		_startingRoom->enableExit();
	}
	else{
		_startingRoom->enableStairsUp();
	}

	SetCurrentRoom(_startingRoom);
}

Room*
Map::GetCurrentRoom(){
	return _currentRoom;
}

void
Map::SetCurrentRoom(Room* room){
	_currentRoom = room;
}


//create a random item here?
void
Map::CreateRoom(Room* room, int x, int y, bool mainRoad, int current_length, int max_length){

	if (x < 0 || x >= matrixWidth || y < 0 || y >= matrixHeight){
		//throw Exception();
	}
	
	bool pathNorthValid = false;
	bool pathEastValid = false;
	bool pathSouthValid = false;
	bool pathWestValid = false;
	int pathCount = 0;

	int northY = y - 1;
	if (northY >= 0){
		if (matrix[x][northY] == nullptr){//north
			pathNorthValid = true;
			pathCount++;
		}
	}
	int eastX = x + 1;
	if (eastX < matrixWidth){
		if (matrix[eastX][y] == nullptr){//east
			pathEastValid = true;
			pathCount++;
		}
	}
	int southY = y + 1;
	if (southY < matrixHeight){
		if (matrix[x][southY] == nullptr){//south
			pathSouthValid = true;
			pathCount++;
		}
	}
	int westX = x - 1;
	if (westX >= 0){
		if (matrix[westX][y] == nullptr){//west
			pathWestValid = true;
			pathCount++;
		}
	}


	if (pathCount == 0 || current_length >= max_length){
		if (mainRoad){
			if (_map_level >= _max_map_level){
				room->enableBoss();
			}
			else{
				room->enableStairsDown();
			}
		}
		return;
	}


	bool pathNorthMain = false;
	bool pathEastMain = false;
	bool pathSouthMain = false;
	bool pathWestMain = false;

	bool mainRoadSecured = false;
	if (mainRoad){
		while (!mainRoadSecured){
			int randomNr = _random->getRandom(1, 4);
			switch (randomNr){
			case 1:
				if (pathNorthValid){
					pathNorthMain = true;
					mainRoadSecured = true;
				}
				break;
			case 2:
				if (pathEastValid){
					pathEastMain = true;
					mainRoadSecured = true;
				}
				break;
			case 3:
				if (pathSouthValid){
					pathSouthMain = true;
					mainRoadSecured = true;
				}
				break;
			case 4:
				if (pathWestValid){
					pathWestMain = true;
					mainRoadSecured = true;
				}
				break;
			}
		}
	}


	int randomNr = _random->getRandom(0, 100);
	bool newNorthRoom = false;
	if ((randomNr < newRoomChance && pathNorthValid) || pathNorthMain){
		Room* newRoom = new Room(_map_level);
		newRoom->setRoomSouth(room);
		room->setRoomNorth(newRoom);
		matrix[x][northY] = newRoom;
		newNorthRoom = true;
	}

	randomNr = _random->getRandom(0, 100);
	bool newEastRoom = false;
	if ((randomNr <= newRoomChance && pathEastValid) || pathEastMain){
		Room* newRoom = new Room(_map_level);
		newRoom->setRoomWest(room);
		room->setRoomEast(newRoom);
		matrix[eastX][y] = newRoom;
		newEastRoom = false;
	}

	randomNr = _random->getRandom(0, 100);
	bool newSouthRoom = false;
	if ((randomNr <= newRoomChance && pathSouthValid) || pathSouthMain){
		Room* newRoom = new Room(_map_level);
		newRoom->setRoomNorth(room);
		room->setRoomSouth(newRoom);
		matrix[x][southY] = newRoom;
		newSouthRoom = false;
	}

	randomNr = _random->getRandom(0, 100);
	bool newWestRoom = false;
	if ((randomNr <= newRoomChance && pathWestValid) || pathWestMain){
		Room* newRoom = new Room(_map_level);
		newRoom->setRoomEast(room);
		room->setRoomWest(newRoom);
		matrix[westX][y] = newRoom;
		newWestRoom = false;
	}

	if (pathNorthMain){
		CreateRoom(matrix[x][northY], x, northY, pathNorthMain, current_length + 1, max_length);
	}
	else if (pathEastMain){
		CreateRoom(matrix[eastX][y], eastX, y, pathEastMain, current_length + 1, max_length);
	}
	else if (pathSouthMain){
		CreateRoom(matrix[x][southY], x, southY, pathSouthMain, current_length + 1, max_length);
	}
	else if (pathWestMain){
		CreateRoom(matrix[westX][y], westX, y, pathWestMain, current_length + 1, max_length);
	}

	if (!pathNorthMain && newNorthRoom){
		CreateRoom(matrix[x][northY], x, northY, pathNorthMain, current_length + 1, max_length);
	}
	if (!pathEastMain && newEastRoom){
		CreateRoom(matrix[eastX][y], eastX, y, pathEastMain, current_length + 1, max_length);
	}
	if (!pathSouthMain && newSouthRoom){
		CreateRoom(matrix[x][southY], x, southY, pathSouthMain, current_length + 1, max_length);
	}
	if (!pathWestMain && newWestRoom){
		CreateRoom(matrix[westX][y], westX, y, pathWestMain, current_length + 1, max_length);
	}

}

void
Map::PrintMap(){

	cout << endl << endl << "Dungeon Map:" << endl;

	for (int i = 0; i < matrixHeight; i++){
		for (int j = 0; j < matrixWidth; j++){
			if (matrix[j][i] != nullptr && (matrix[j][i]->getVisited())){
				if (matrix[j][i]->getExit()){
					cout << "E";
				}
				else if (matrix[j][i]->getStairsUp()){
					cout << "S";
				}
				else if (matrix[j][i]->getBoss()){
					cout << "B";
				}
				else if (matrix[j][i]->getStairsDown()){
					cout << "X";
				}
				else if (matrix[j][i] == _currentRoom){
					cout << "0";
				}
				else{
					cout << "O";
				}
			}
			else{
				cout << ".";
			}

			if (matrix[j][i] != nullptr){
				if ((matrix[j][i]->getRoomEast() != nullptr) && (matrix[j][i]->getVisited() || matrix[j + 1][i]->getVisited())){
					cout << "-";
				}
				else{
					cout << " ";
				}
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
		for (int j = 0; j < matrixWidth; j++){

			if (matrix[j][i] != nullptr){
				if (matrix[j][i]->getRoomSouth() != nullptr && (matrix[j][i]->getVisited() || matrix[j][i + 1]->getVisited())){
					cout << "| ";
				}
				else{
					cout << "  ";
				}
			}
			else{
				cout << "  ";
			}

		}
		cout << endl;
	}
	cout << endl << endl << "Legenda:" << endl;
	cout << "|- : Halls" << endl;
	cout << "0  : Your position" << endl;
	cout << "O  : Normal room" << endl;
	cout << "E  : Exit" << endl;
	cout << "S  : Stairs up" << endl;
	cout << "X  : Stairs down" << endl;
	cout << "B  : Bossroom" << endl;
	cout << ".  : Unexplored space" << endl;
}

Map::~Map()
{
	//delete _startingRoom;
	for (int i = 0; i < matrixHeight; i++){
		for (int j = 0; j < matrixWidth; j++){
			if (matrix[j][i] != nullptr) delete matrix[j][i];
		}
	}

}

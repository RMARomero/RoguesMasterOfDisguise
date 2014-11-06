#pragma once
#include <vector>
#include "Room.h"

const int matrixWidth = 20;
const int matrixHeight = 10;

class Map
{
private:
	Room* matrix[matrixWidth][matrixHeight];
	Room* _startingRoom;

	Room* _currentRoom;
	int _currentRoomX;
	int _currentRoomY;
	int newRoomChance;

	RandomValue* _random;
	int _map_level;
	int _max_map_level;
	void CreateLevel(int DungeonLevel);
	void CreateRoom(Room* room, int x, int y, bool mainRoad, int currentLength, int maxLength);
public:
	Map();
	Map(int map_level, int max_map_level, int max_length);
	Room* GetCurrentRoom();
	void SetCurrentRoom(Room* room);
	void PrintMap();
	~Map();
};


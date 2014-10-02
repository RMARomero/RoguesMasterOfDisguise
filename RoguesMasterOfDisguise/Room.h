#pragma once
#include <string>
#include <vector>
#include "RandomValue.h"
#include "Enemy.h"

class Room
{
private:

	bool _visited;
	bool _stairsUp;
	bool _stairsDown;
	bool _exit;
	int _room_level;

	bool _boss = false;

	Room* _roomNorth;
	Room* _roomEast;
	Room* _roomSouth;
	Room* _roomWest;
	std::string _roomSize;
	std::string _roomCondition;
	std::string _roomDecoration;
	std::string _roomLightning;
	int _roomTrap;

	RandomValue* _random;
	void setRoomSize();
	void setRoomCondition();
	void setRoomDecoration();
	void setRoomLightning();
	std::string getEnemyInformation();
	std::string getExitInformation();
	std::string getVisitedInformation();

	std::vector<Enemy*> _enemies;
	void spawnEnemies();
public:
	Room(int room_level);
	void setRoomNorth(Room* room);
	void setRoomEast(Room* room);
	void setRoomSouth(Room* room);
	void setRoomWest(Room* room);
	Room* getRoomNorth();
	Room* getRoomEast();
	Room* getRoomSouth();
	Room* getRoomWest();
	void setVisited();
	bool getVisited();
	void enableStairsUp();
	void enableStairsDown();
	void enableExit();
	bool getStairsUp();
	bool getStairsDown();
	bool getExit();

	void enableBoss();
	bool getBoss();

	std::string getChoiceInformation();
	std::string getMoveChoices();
	std::string toString();
	~Room();
};


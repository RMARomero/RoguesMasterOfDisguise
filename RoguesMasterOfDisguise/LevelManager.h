#pragma once
#include "Map.h"
#include <map>

class LevelManager
{
private:
	int _currentLevel;
	const int _maxLevel = 10;
	std::map<int, Map*> _levels;
public:
	LevelManager();
	Map* GetCurrentMap();
	void DecreaseCurrentLevel();
	void IncreaseCurrentLevel();
	~LevelManager();
};


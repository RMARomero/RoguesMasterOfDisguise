#include "stdafx.h"
#include "LevelManager.h"


LevelManager::LevelManager()
{
	_currentLevel = 1;

	for (int i = 1; i <= _maxLevel; i++){
		Map* map = new Map(i, _maxLevel);
		_levels[i] = *map;
	}

}

Map* 
LevelManager::GetCurrentMap(){
	return &_levels[_currentLevel];
}

void 
LevelManager::DecreaseCurrentLevel(){
	if (_currentLevel > 1)
		_currentLevel--;
}

void 
LevelManager::IncreaseCurrentLevel(){
	if (_currentLevel < 10)
		_currentLevel++;
}

LevelManager::~LevelManager()
{
	//for (int i = 1; i <= _maxLevel; i++){
	//	Map* map = &_levels[i];
	//	delete map;
	//}
}

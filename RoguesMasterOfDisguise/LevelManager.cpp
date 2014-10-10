#include "stdafx.h"
#include "LevelManager.h"

using namespace std;

LevelManager::LevelManager()
{
	_currentLevel = 1;

	for (int i = 1; i <= _maxLevel; i++){
		_levels[i] = new Map(i, _maxLevel);
		//_levels.insert(pair<int,Map*>(i, new Map(i, _maxLevel)));
	}

}

Map* 
LevelManager::GetCurrentMap(){
	return _levels.find(_currentLevel)->second;
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
	
	/*
	for (map<int, Map*>::iterator it = _levels.begin(); it != _levels.end(); it++)
	{
		delete it->second;
		_levels.erase(it);
	}
	*/

	for (int i = 1; i <= _maxLevel; i++){
		delete _levels.at(i);
	}

	//delete &_levels;

}

#include "stdafx.h"
#include "LevelManager.h"

using namespace std;

LevelManager::LevelManager()
{
	_currentLevel = 1;

	for (int i = 1; i <= _maxLevel; i++){
		_levels[i] = new Map(i, _maxLevel, 1+i*2);
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
	if (_currentLevel < _maxLevel)
		_currentLevel++;
}

LevelManager::~LevelManager()
{
	
	for (int i = 1; i <= _maxLevel; i++){
		delete _levels.at(i);
	}

}

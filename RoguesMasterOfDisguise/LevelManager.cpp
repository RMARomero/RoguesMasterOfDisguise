#include "stdafx.h"
#include "LevelManager.h"

using namespace std;

LevelManager::LevelManager()
{
	_levels = new map<int, Map*>();
	_currentLevel = 1;

	for (int i = 1; i <= _maxLevel; i++){
		//_levels[i] = new Map(i, _maxLevel);
		//std::pair<char, int>('a', 100
		_levels->insert(pair<int,Map*>(i, new Map(i, _maxLevel)));
	}

}

Map* 
LevelManager::GetCurrentMap(){
	return _levels->find(_currentLevel)->second;
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
	delete _levels;
	/*for (int i = 0; i < _levels->size(); i++){
		delete _levels->at(i);
	}*/
}

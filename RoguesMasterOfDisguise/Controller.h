#pragma once
#include "Hero.h"
#include "LevelManager.h"

class GameState; class Controller
{
private:
	Hero* _hero;
	LevelManager* _levelManager;
	GameState* _currentGameState;
	GameState* _gameStateInitiate;
	GameState* _gameStateChoice;
	GameState* _gameStateCombat;
	GameState* _gameStateInventory;
	GameState* _gameStateSearch;
public:
	Controller();
	std::string getInput(std::string input);
	void setCurrentGameState(int GameState);
	void PrintMap();
	void SaveGame();
	void DeleteGame();
	GameState* getCurrentGameState();
	~Controller();

	const int INITIATE_STATE = 0;
	const int CHOICE_STATE = 1;
	const int COMBAT_STATE = 2;
	const int INVENTORY_STATE = 3;
	const int SEARCH_STATE = 4;
};


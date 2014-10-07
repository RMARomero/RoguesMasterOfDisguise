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
public:
	Controller();
	std::string getInput(std::string input);
	void setCurrentGameState(int GameState);
	//GameState* getCurrentGameState();
	~Controller();

	const int INITIATE_STATE = 0;
	const int CHOICE_STATE = 1;
	const int COMBAT_STATE = 2;
};


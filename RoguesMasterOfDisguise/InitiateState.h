#pragma once
#include "GameState.h"

class InitiateState: public GameState
{
public:
	InitiateState(Hero *player, LevelManager *lvlManager, Controller* controller);
	std::string processInput(std::string input);
	~InitiateState();
};


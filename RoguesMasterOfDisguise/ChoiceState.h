#pragma once
#include "GameState.h"

class ChoiceState: public GameState
{
public:
	ChoiceState(Hero *player, LevelManager *lvlManager, Controller* controller);
	virtual std::string processInput(std::string input);
	~ChoiceState();
};


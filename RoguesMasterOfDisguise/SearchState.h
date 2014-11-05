#pragma once
#include "GameState.h"
#include "RandomValue.h"

class SearchState : public GameState
{
public:
	SearchState(Hero *player, LevelManager *lvlManager, Controller* controller);
	virtual ~SearchState();
	std::string processInput(std::string input);
private:
	RandomValue* _random;
};


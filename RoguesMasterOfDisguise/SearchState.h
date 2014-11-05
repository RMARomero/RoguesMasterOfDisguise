#pragma once
#include "GameState.h"
class SearchState : public GameState
{
public:
	SearchState(Hero *player, LevelManager *lvlManager, Controller* controller);
	virtual ~SearchState();
	std::string processInput(std::string input);
};


#pragma once
#include "GameState.h"
class InventoryState : public GameState
{
public:
	InventoryState(Hero *player, LevelManager *lvlManager, Controller* controller);
	virtual ~InventoryState();
	std::string processInput(std::string input);
};


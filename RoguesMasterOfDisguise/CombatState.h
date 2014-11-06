#pragma once
#include "GameState.h"

class CombatState: public GameState
{
private:
	int m_fleeChance = 66;// out of 100, so pretty much percentage

public:
	CombatState(Hero *player, LevelManager *lvlManager, Controller* controller);
	std::string processInput(std::string input);
	std::string Fight(bool playerTurn, std::vector<Enemy*>& enemies, Hero* player);
	~CombatState();
};


#include "stdafx.h"
#include "CombatState.h"

using namespace std;

CombatState::CombatState(Hero *player, LevelManager *levelManager, Controller* controller)
{
	_current_step = 1;
	_hero = player;
	_levelManager = levelManager;
	_controller = controller;

}

string 
CombatState::processInput(string input){
	return input;
}


CombatState::~CombatState()
{
}

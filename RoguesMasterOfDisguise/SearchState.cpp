#include "stdafx.h"
#include "SearchState.h"

using namespace std;

SearchState::SearchState(Hero *player, LevelManager *lvlManager, Controller* controller)
{
	_hero = player;
	_levelManager = lvlManager;
	_controller = controller;
}


SearchState::~SearchState()
{
}

string SearchState::processInput(string input)
{
	string result = "";

	return result;
}
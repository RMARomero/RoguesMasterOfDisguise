#include "stdafx.h"
#include "ChoiceState.h"

#include <iostream>

using namespace std;

ChoiceState::ChoiceState(Hero *player, LevelManager *levelManager, Controller* controller)
{
	_current_step = 1;
	_hero = player;
	_levelManager = levelManager;
	_controller = controller;


}

string 
ChoiceState::processInput(string input){
	string result = "";
	Room* nextRoom = nullptr;

	if (input == "fight"){
		_controller->setCurrentGameState(_controller->COMBAT_STATE);
		result = "Combat Started: {}";
	}
	if (input == "flee" || input == "move"){
		result = _levelManager->GetCurrentMap()->GetCurrentRoom()->getMoveChoices();
	}
	else if (input == "map"){
		_levelManager->GetCurrentMap()->PrintMap();
		result = _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
	}

	/* Switch Room: */
	if (input == "north"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomNorth();
	}
	else if (input == "east"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomEast();
	}
	else if (input == "south"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomSouth();
	}
	else if (input == "west"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomWest();
	}
	if (nextRoom != nullptr){
		_levelManager->GetCurrentMap()->SetCurrentRoom(nextRoom);
		result = _levelManager->GetCurrentMap()->GetCurrentRoom()->toString();
	}

	/* Switch Maps */
	if (input == "stairs"){
		if (_levelManager->GetCurrentMap()->GetCurrentRoom()->getStairsUp()){
			_levelManager->DecreaseCurrentLevel();
		}
		else if (_levelManager->GetCurrentMap()->GetCurrentRoom()->getStairsDown()){
			_levelManager->IncreaseCurrentLevel();
		}
		result = _levelManager->GetCurrentMap()->GetCurrentRoom()->toString();
	}
	else if (input == "exit"){
		if (_levelManager->GetCurrentMap()->GetCurrentRoom()->getExit()){
			result = "exit";
		}
	}


	return result;
}

ChoiceState::~ChoiceState()
{
}

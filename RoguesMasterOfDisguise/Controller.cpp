#include "stdafx.h"
#include "Controller.h"

#include "InitiateState.h"
#include "ChoiceState.h"
#include "CombatState.h"
#include "InventoryState.h"

#include <sstream>
#include <iostream>

using namespace std;


Controller::Controller()
{
	_hero = new Hero();
	_levelManager = new LevelManager();

	_gameStateInitiate = new InitiateState(_hero, _levelManager, this);
	_gameStateChoice = new ChoiceState(_hero, _levelManager, this);
	_gameStateCombat = new CombatState(_hero, _levelManager, this);
	_gameStateInventory = new InventoryState(_hero, _levelManager, this);
	setCurrentGameState(INITIATE_STATE);
}


std::string 
Controller::getInput(string input)
{
	return _currentGameState->processInput(input);
}

void 
Controller::setCurrentGameState(int GameState){

	if (GameState == INITIATE_STATE){
		_currentGameState = _gameStateInitiate;
	}
	else if (GameState == CHOICE_STATE){
		_currentGameState = _gameStateChoice;
	}
	else if (GameState == COMBAT_STATE){
		_currentGameState = _gameStateCombat;
	}
	else if (GameState == INVENTORY_STATE)
		_currentGameState = _gameStateInventory;
}

//GameState* Controller::getCurrentGameState(){
//	return _currentGameState;
//}

Controller::~Controller()
{
	delete _hero;
	delete _levelManager;
	delete _gameStateInitiate;
	delete _gameStateChoice;
	delete _gameStateCombat;
	delete _gameStateInventory;
}

void Controller::PrintMap(){
	_levelManager->GetCurrentMap()->PrintMap();
}
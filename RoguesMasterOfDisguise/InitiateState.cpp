#include "stdafx.h"
#include "InitiateState.h"
#include "Hero.h"
#include "LevelManager.h"
#include <iostream>

using namespace std;

InitiateState::InitiateState(Hero *player, LevelManager *levelManager, Controller* controller)
{
	_current_step = 1;
	_hero = player;
	_levelManager = levelManager;
	_controller = controller;

	cout << "--------------------------\n--    The underworld    --\n--------------------------\n\n" << endl;
	cout << "\"You... \How.. did you get.. here?... \nIt matters ... not. You must ... ... save ... them...\"\n\n*cough cough*.\n\n\"What is your name...?\"\n " << endl;

}

string 
InitiateState::processInput(string input){

	string result = "";

	if (_current_step == 1){
		_hero->setName(input);
		result = "\"So your name is '" + input + "'.\"\n\n*cough cough*\n\n\"Please, enter this dungeon and save them... before.. it is... ...\"\n\n\nI'm not sure what the old man tried to say in the end, while he passed away.\nAnyways, what should i do?\n\n{enter, leave}\n";
		_current_step++;
	}
	else if (_current_step == 2){
		if (input == "leave"){
			result = "___exit___";
		}
		else if (input == "enter"){
			result = "enter";
			result = _levelManager->GetCurrentMap()->GetCurrentRoom()->toString();
			_controller->setCurrentGameState(_controller->CHOICE_STATE);
		}
		else{
			result = "What should i do?\n\n{enter, leave}\n";
		}
	}

	return result;

}

InitiateState::~InitiateState()
{
}

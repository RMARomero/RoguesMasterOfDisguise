#include "stdafx.h"
#include "InputManager.h"
#include "RandomValue.h"
#include "Factory.h"
#include <iostream>

using namespace std;

InputManager::InputManager()
{
	_controller = new Controller();
	_playing = true;
	while (_playing){
		cout << endl << getInput() << endl;
	}
}

std::string 
InputManager::getInput()
{
	_controller->SaveGame();
	string input = "";
	getline(cin, input);
	
	string result = _controller->getInput(input);

	const std::string ext("___exit___");
	if (result.size() >= ext.size() && result.substr(result.size() - ext.size()) == "___exit___")
	{
		result = result.substr(0, result.size() - ext.size());
		_playing = false;
		result += "\n\n--------------------------\nAnd so the journey ends...\n--------------------------\n\n";
		result += "\n";
		result += "\n";
		result += "\nPress any key to continue...\n";
		
		cout << result;
		result = "";
		getline(cin, input);
	}

	return result;
}

InputManager::~InputManager()
{
	delete _controller;
	delete RandomValue::getInstance();
	delete Factory::getInstance();
}


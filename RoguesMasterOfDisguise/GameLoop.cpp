#include "stdafx.h"
#include "GameLoop.h"
#include "RandomValue.h"
#include "Factory.h"

//#include <sstream>
#include <iostream>

using namespace std;


GameLoop::GameLoop()
{
	_controller = new Controller();
	_playing = true;
	while (_playing){
		cout << endl << getInput() << endl;
		//_controller->PrintMap();
	}
}

std::string 
GameLoop::getInput()
{
	_controller->SaveGame();
	string input = "";
	getline(cin, input);
	//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	
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

GameLoop::~GameLoop()
{
	delete _controller;
	delete RandomValue::getInstance();
	delete Factory::getInstance();
	//TODO: DELETE RANDOM SINGLETON
	//TODO: FIX MEMLEAKS IN ROOM AND MAP
}


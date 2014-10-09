#include "stdafx.h"
#include "GameLoop.h"
#include "RandomValue.h"
#include "ReadTextFile.h"

//#include <sstream>
#include <iostream>

using namespace std;


GameLoop::GameLoop()
{
	_controller = new Controller();
	_playing = true;
	while (_playing){
		cout << endl << getInput() << endl;
	}
}

std::string 
GameLoop::getInput()
{
	string input = "";
	getline(cin, input);
	string result = _controller->getInput(input);

	const std::string ext("___exit___");
	if (result.size() >= ext.size() &&
		result.substr(result.size() - ext.size()) == "___exit___")
	{
		result = result.substr(0, result.size() - ext.size());
		_playing = false;
		result += "\n\n--------------------------\nAnd so the journey ends...\n--------------------------\n\n";
	}

	
	return result;
}

GameLoop::~GameLoop()
{
	delete _controller;
	delete RandomValue::getInstance();
	delete ReadTextFile::getInstance();
	//TODO: DELETE RANDOM SINGLETON
}


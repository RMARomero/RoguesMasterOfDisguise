#include "stdafx.h"
#include "GameLoop.h"

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
	if (result == "exit"){
		_playing = false;
		result = "--------------------------\nAnd so the journey ends...\n--------------------------\n\n";
	}
	return result;
}

GameLoop::~GameLoop()
{
	delete _controller;
	//TODO: DELETE RANDOM SINGLETON
}


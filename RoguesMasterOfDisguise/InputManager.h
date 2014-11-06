#pragma once
#include "Controller.h"

class InputManager
{
private:
	bool _playing;
	Controller* _controller;
public:
	InputManager();
	std::string getInput();
	bool getPlayingStatus();
	~InputManager();
};


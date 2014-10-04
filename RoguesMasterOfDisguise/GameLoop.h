#pragma once
#include "Controller.h"

class GameLoop
{
private:
	bool _playing;
	Controller* _controller;
public:
	GameLoop();
	std::string getInput();
	bool getPlayingStatus();
	~GameLoop();
};


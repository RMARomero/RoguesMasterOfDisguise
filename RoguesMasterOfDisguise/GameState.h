#pragma once
#include "Hero.h"
#include "LevelManager.h"
#include "Controller.h"

class GameState
{
protected:
	int _current_step;
	Hero* _hero;
	LevelManager* _levelManager;
	Controller* _controller;
public:
	GameState();
	virtual std::string processInput(std::string input);
	~GameState();
};


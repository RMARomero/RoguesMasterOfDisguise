// RoguesMasterOfDisguise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"
#include "ReadTextFile.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop* game = new GameLoop();
	delete game;
}


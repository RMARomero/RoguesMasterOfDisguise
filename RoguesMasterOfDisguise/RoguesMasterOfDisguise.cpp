// RoguesMasterOfDisguise.cpp : Defines the entry point for the console application.
//
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "stdafx.h"
#include "GameLoop.h"
#include "ReadTextFile.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	GameLoop* game = new GameLoop();
	delete game;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


// RoguesMasterOfDisguise.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <crtdbg.h>
#include "stdafx.h"
#include "GameLoop.h"
#include "ReadTextFile.h"
#include <iostream>

#ifdef CRTDBG_MAP_ALLOC
HANDLE stream;
stream = CreateFile(dmpFilename, GENERIC_WRITE, FILE_SHARE_WRITE,
	NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_ERROR, stream);
_CrtSetReportFile(_CRT_WARN, stream);
_CrtDumpMemoryLeaks();
CloseHandle(stream);
#endif

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	GameLoop* game = new GameLoop();
	delete game;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


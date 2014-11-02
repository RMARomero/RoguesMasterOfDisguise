#include "stdafx.h"
#include "InventoryState.h"
#include <sstream>

using namespace std;

InventoryState::InventoryState(Hero *player, LevelManager *lvlManager, Controller* controller)
{
	_hero = player;
	_levelManager = lvlManager;
	_controller = controller;
}


InventoryState::~InventoryState()
{
}

string InventoryState::processInput(string input)
{
	string result = "";

	try
	{
		std::stringstream ss(input);

		unsigned int i;
		if ((ss >> i).fail() || !(ss >> std::ws).eof())
		{
			throw std::bad_cast();
		}

		if (i > 0 && i <= _hero->getInventory().size())
		{
			i--; //index - 1 to get the right item
			string res = _hero->getInventory().at(i)->Use();
			int heal = stoi(res);

			_hero->Heal(heal);
			_controller->setCurrentGameState(_controller->CHOICE_STATE);

			result += "You healed for " + res + " ammount of health points";
			result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();		
		}
		else
		{
			result += "Invalid input.";
			result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
		}
	}
	catch (...)
	{
		result += "Invalid input.";
		result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
	}

	return result;
}

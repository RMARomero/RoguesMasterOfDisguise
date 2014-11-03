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

	if (!_hero->getInventory().empty())
	{
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
				string res = _hero->getInventory().at(i)->Use(_hero);
				//_hero->getInventory().erase( _hero->getInventory().begin() + i ); //exception range out of index 

				_controller->setCurrentGameState(_controller->CHOICE_STATE);

				result += res;
				result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
			}
			else
			{
				_controller->setCurrentGameState(_controller->CHOICE_STATE);

				result += "I don't have any items on that spot...";
				result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
			}
		}
		catch (...)
		{
			_controller->setCurrentGameState(_controller->CHOICE_STATE);

			result += "Incorrect input.";
			result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
		}
	}
	else
	{
		result += "My inventory is empty!";

		_controller->setCurrentGameState(_controller->CHOICE_STATE);
		result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
	}
	
	return result;
}

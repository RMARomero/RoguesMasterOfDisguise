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

	if (input == "inventory" && !_hero->getInventory()->empty())
	{
		result += "\nSelect which item you would like to use.\n";
		result += "\nOr type <back> to exit inventory.\n";
	}
	else if (!_hero->getInventory()->empty())
	{
		if (input != "back")
		{
			try
			{
				std::stringstream ss(input);

				unsigned int i;
				if ((ss >> i).fail() || !(ss >> std::ws).eof())
				{
					throw std::bad_cast();
				}

				if (i > 0 && i <= _hero->getInventory()->size())
				{
					i--; //index - 1 to get the right item
					Item* item = _hero->getInventory()->at(i);
					string res = item->Use(_hero);
					result += res;

					_hero->getInventory()->erase(_hero->getInventory()->begin() + i);

					//memory cleanup
					delete item;
					item = nullptr;

					_controller->setCurrentGameState(_controller->CHOICE_STATE);
					if (!_hero->IsAlive()){
						result += "\nYou died. You weren't able to save... them... ___exit___";
					}
					else{
						result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
					}

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
			_controller->setCurrentGameState(_controller->CHOICE_STATE);
			result += "Exiting inventory...";
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

#include "stdafx.h"
#include "SearchState.h"
#include "Item.h"
#include "Room.h"

using namespace std;

SearchState::SearchState(Hero *player, LevelManager *lvlManager, Controller* controller)
{
	_hero = player;
	_levelManager = lvlManager;
	_controller = controller;
}


SearchState::~SearchState()
{
}

string SearchState::processInput(string input)
{
	string result = "\n";

	Room* currentRoom = nullptr;

	if (input == "search")
	{
		int chance = _random->getRandom(0, 99);

		Item* foundItem = _levelManager->GetCurrentMap()->GetCurrentRoom()->searchRoom(chance);
		currentRoom = _levelManager->GetCurrentMap()->GetCurrentRoom();

		if (foundItem == nullptr && currentRoom->isTrapTriggered())
		{
			if (currentRoom->isDodgedTrap())
			{
				result += "\nYou triggerd a hazardous trap! But you manage to dodge the damage in time!";
			}
			else
			{
				_hero->doTrapDamage(currentRoom->getTrapDamage());
				result += "\nYou triggerd a hazardous trap! You took " + to_string(currentRoom->getTrapDamage()) + "!";
			}		
		}
		else if (foundItem == nullptr && !currentRoom->isTrapTriggered())
		{
			result += "\nHmmm, didnt find anything...";
		}
		else
		{
			result += "\nBingo! I got a " + foundItem->getName() + ". " + foundItem->getDescription() + ".";
			_hero->addItemToInventory(foundItem);
		}

		_levelManager->GetCurrentMap()->GetCurrentRoom()->setItemPointerToNull();

		_controller->setCurrentGameState(_controller->CHOICE_STATE);

		result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
	}

	currentRoom = nullptr;

	return result;
}
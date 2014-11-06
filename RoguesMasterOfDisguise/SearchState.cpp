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

	_sprungTrap = false;
}


SearchState::~SearchState()
{
}

string SearchState::processInput(string input)
{
	string result = "\n";

	Room* currentRoom = nullptr;

	//this things is so wrong
	if (input == "search")
	{
		int chance = _random->getRandom(0, 99);

		Item* foundItem = _levelManager->GetCurrentMap()->GetCurrentRoom()->searchRoom(chance);
		currentRoom = _levelManager->GetCurrentMap()->GetCurrentRoom();

		//check for traps first
		if (foundItem == nullptr && currentRoom->getRoomTrap() != nullptr)
		{
			if (currentRoom->getRoomTrap()->isTrapTriggered() && _sprungTrap == false)
			{
				if (currentRoom->getRoomTrap()->isTrapDodged())
				{
					_sprungTrap = true;
					result += "\nYou triggered a trap! ";
					result += currentRoom->getRoomTrap()->getDescription() + ". But you manage to dodge the damage in time!";
				}
				else
				{
					_sprungTrap = true;
					result += "\nYou triggered a trap! ";
					_hero->doTrapDamage(currentRoom->getRoomTrap()->getTrapDamage());
					result += currentRoom->getRoomTrap()->getDescription() + ". You took " + to_string(currentRoom->getRoomTrap()->getTrapDamage()) + "!";
				}
			}
			else
				result += "\nHmmm, didnt find anything...";
		}
		else if (foundItem == nullptr)
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
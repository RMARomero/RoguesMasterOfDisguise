#include "stdafx.h"
#include "SearchState.h"
#include "Item.h"

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

	if (input == "search")
	{
		int chance = _random->getRandom(0, 99);

		Item* foundItem = _levelManager->GetCurrentMap()->GetCurrentRoom()->searchRoom(chance);

		if (foundItem == nullptr)
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

	return result;
}
#include "stdafx.h"
#include "CombatState.h"
#include "RandomValue.h"
#include <sstream>
#include <algorithm>
using namespace std;

CombatState::CombatState(Hero *player, LevelManager *levelManager, Controller* controller)
{
	_current_step = 1;
	_hero = player;
	_levelManager = levelManager;
	_controller = controller;

}

string 
CombatState::processInput(string input){
	string result = "";
	Room* nextRoom = nullptr;
	bool enemyAttack = false;
	bool fleeAttempt = false;

	if (input == "attack"){
		result = Fight(true, *_levelManager->GetCurrentMap()->GetCurrentRoom()->getEnemies(), _hero);
		std::vector<Enemy*>* enemies = _levelManager->GetCurrentMap()->GetCurrentRoom()->getEnemies();
		if (enemies->size() > 0){
			enemyAttack = true;
		}
		else{
			_controller->setCurrentGameState(_controller->CHOICE_STATE);
			result += "You have slain the enemies! Now what?";
			result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
		}
	}
	else if (input == "flee"){
		result = "Which way?\n\n";
		result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getMoveChoices();
	}
	else if (input == "inventory"){
		//result = "You don't have any items right now...";
		//result += _levelManager->GetCurrentMap()->GetCurrentRoom()->getChoiceInformation();
		result += "I might need something in a pinch...";
		_hero->printInventory();
		_controller->setCurrentGameState(_controller->INVENTORY_STATE);
	}

	else if (input == "stats"){
		result = _hero->getStats();
		result += "\n\n"+_levelManager->GetCurrentMap()->GetCurrentRoom()->getAttackChoices();
	}

	/* Switch Room: */
	else if (input == "north"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomNorth();
		fleeAttempt = true;
	}
	else if (input == "east"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomEast();
		fleeAttempt = true;
	}
	else if (input == "south"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomSouth();
		fleeAttempt = true;
	}
	else if (input == "west"){
		nextRoom = _levelManager->GetCurrentMap()->GetCurrentRoom()->getRoomWest();
		fleeAttempt = true;
	}
	else{
		result += "Invalid input.\n" + _levelManager->GetCurrentMap()->GetCurrentRoom()->getAttackChoices();
	}

	if (fleeAttempt){
		if (nextRoom != nullptr){
			int chance = RandomValue::getInstance()->getRandom(0, 100);
			if (chance <= 66){
				_levelManager->GetCurrentMap()->SetCurrentRoom(nextRoom);
				_controller->setCurrentGameState(_controller->CHOICE_STATE);
				result = "You succesfully ran from the enemies.\n\n";
				result += _levelManager->GetCurrentMap()->GetCurrentRoom()->toString();
			}
			else{
				result = "You weren't able to run!.\n\n";
				enemyAttack = true;
			}
		}
		else{
			result = "There is no path leading this way!.\n\n";
			enemyAttack = true;
		}


	}

	if (enemyAttack){
		result += Fight(false, *_levelManager->GetCurrentMap()->GetCurrentRoom()->getEnemies(), _hero);

		const std::string ext("___exit___");
		if (!(result.size() >= ext.size() && result.substr(result.size() - ext.size()) == "___exit___")){
			result += "\n" + _levelManager->GetCurrentMap()->GetCurrentRoom()->getAttackChoices();
		}
	}


	return result;
}



string CombatState::Fight(bool playerTurn, std::vector<Enemy*>& enemies, Hero* player){
	string result = "";

	if (enemies.size() <= 0){
		//error
		return "Something went ";
	}

	if (playerTurn){

		/* // AOE:
		vector< Enemy* >::iterator it = enemies.begin();
		while (it != enemies.end()) {
			Enemy* enemy = (*it);
			int damage = enemy->DoDamage(player->getCurrentAttack());
			result += ("You attack " + enemy->GetName() + ", dealing " + to_string(damage) + " damage.");

			if (!enemy->IsAlive()){
				bool levelUp = player->addExperience(enemy->GetExperienceOnKill());
				result += "\nYou killed " + enemy->GetName() + ". You gained " + to_string(enemy->GetExperienceOnKill()) + " experience!\n";
				if (levelUp){
					result += "Congratulations! You are now level " + to_string(player->getLevel()) + " !\n";
				}
				it = enemies.erase(it);
				//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
			}
			else{
				result += " "+enemy->GetBattleStatus() + "\n";
				++it;
			}
		}
		*/

		int position = RandomValue::getInstance()->getRandom(0, enemies.size());

		Enemy* enemy = enemies.at(position);
		int damage = enemy->DoDamage(player->getCurrentAttack());
		result += ("You attack " + enemy->GetName() + ", dealing " + to_string(damage) + " damage.");

		if (!enemy->IsAlive()){
			bool levelUp = player->addExperience(enemy->GetExperienceOnKill());
			result += "\nYou killed " + enemy->GetName() + ". You gained " + to_string(enemy->GetExperienceOnKill()) + " experience!\n";
			if (levelUp){
				result += "Congratulations! You are now level " + to_string(player->getLevel()) + " !\n";
			}
			enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
		}
		else{
			result += " " + enemy->GetBattleStatus() + "\n";
		}
		

	}
	else{

		int position = RandomValue::getInstance()->getRandom(0, enemies.size());

		Enemy* enemy = enemies.at(position);
		int damage = player->DoDamage(enemy->getCurrentAttack());
		result += (enemy->GetName() + " attacks you, dealing " + to_string(damage) + " damage.");
		if (!player->IsAlive()){
			result += "\nYou died. You weren't able to save... them... ___exit___";
		}
		else{
			result += " You have " + to_string(player->getCurrentHealth()) + " health left. \n";
		}
		
	}

	return result;
}


CombatState::~CombatState()
{
}


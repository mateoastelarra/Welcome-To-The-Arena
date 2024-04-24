#include "Battle.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <list>
#include "Helpers.h"

Battle::Battle(int numberOfEnemies, int level, Player* player)
{
	CurrentPlayer = player;
	int Index = 0;
	while (Index < numberOfEnemies)
	{
		Enemy* enemyToAdd = new Enemy(1);
		Enemies.push_back(enemyToAdd);
		Index++;
	}
	StartBattle();
}

Battle::~Battle()
{
	for (Character* character : Enemies) {
		delete character;
	}
}

void Battle::StartBattle()
{
	FillPlayerAndEnemiesVector();
	int round = 1;
	while (Enemies.size() > 0 && !CurrentPlayer->GetIsDead())
	{
		if (round == 1)
		{
			Helpers::WaitForPlayerResponse("to start the battle.");
		}
		else
		{
			Helpers::WaitForPlayerResponse("for next round.");
		}	
		std::cout << "Round " << round << " starts:" << std::endl;
		Helpers::WaitForSeconds(WaitTime);
		TakeRound();
		round++;
	}
	EndBattle();
}

void Battle::EndBattle()
{
	if (CurrentPlayer->GetIsDead())
	{
		std::cout << "GAME OVER" << std::endl;
	}
	else
	{
		std::cout << "YOU DEFEATED YOUR ENEMIES." << std::endl;
		Helpers::WaitForSeconds(WaitTime);
		CurrentPlayer->ImprovePlayer();
	}
}

void Battle::TakeRound()
{
	DecideInitiative();
	DecideOrderForBattle();
	Character* ActiveCharacter;
	bool AnEnemyDied = false;
	for (int i = 0; i < PlayerAndEnemies.size(); i++)
	{
		ActiveCharacter = PlayerAndEnemies[i];
		if (dynamic_cast<Enemy*>(ActiveCharacter))
		{
			ActiveCharacter->Attack(CurrentPlayer);
		}
		else
		{
			CurrentPlayer->TakeTurn(Enemies);
			AnEnemyDied = CheckDeaths();
		}
		Helpers::WaitForSeconds(WaitTime);
	}

	if (AnEnemyDied)
	{
		PlayerAndEnemies.clear();
		FillPlayerAndEnemiesVector();
	}

	ResetDefenses();
}

bool Battle::CheckDeaths()
{
	bool AnEnemyDied = false;
	std::list<Character*> EnemiesToRemove;

	for (Character* enemy : Enemies)
	{
		if (enemy->GetIsDead())
		{
			EnemiesToRemove.push_back(enemy);
			AnEnemyDied = true;
		}
	}

	for (Character* enemyToRemove : EnemiesToRemove)
	{
		Enemies.remove(enemyToRemove);
	}

	return AnEnemyDied;
}

void Battle::DecideInitiative()
{
	// Set initiative for enemies
	int NewInitiative = rand() % 20 + 1;
	for (Character* character : Enemies)
	{
		NewInitiative = NewInitiative + character->GetBaseInitiative();
		character->SetInitiative(NewInitiative);
		NewInitiative = rand() % 20 + 1;
	}

	// Set initiative for player
	NewInitiative = NewInitiative + CurrentPlayer->GetBaseInitiative();
	CurrentPlayer->SetInitiative(NewInitiative);
}

void Battle::DecideOrderForBattle()
{
	// Order PlayerAndEnemies vector from max initiative to least initiative
	// Use linear search because it´s going to be a small vector
	for (int j = 0; j < PlayerAndEnemies.size(); j++)
	{
		int MaxInitiativeIndex = j;
		int MaxInitiative = PlayerAndEnemies[j]->GetInitiative();
		
		for (int i = j; i < PlayerAndEnemies.size(); i++)
		{
			int CurrentInitiative = PlayerAndEnemies[i]->GetInitiative();
			if (CurrentInitiative > MaxInitiative)
			{
				MaxInitiativeIndex = i;
				MaxInitiative = PlayerAndEnemies[i]->GetInitiative();
			}
		}
		std::swap(PlayerAndEnemies[j], PlayerAndEnemies[MaxInitiativeIndex]);
	}
}

void Battle::FillPlayerAndEnemiesVector()
{
	PlayerAndEnemies.push_back(CurrentPlayer);
	for (Character* character : Enemies)
	{
		PlayerAndEnemies.push_back(character);
	}
}

void Battle::ResetDefenses()
{
	for (Character* character : PlayerAndEnemies)
	{
		character->BreakDefense();
	}
}


#include "Battle.h"
#include "Enemy.h"
#include <iostream>
#include <list>
#include <chrono>
#include <thread>

Battle::Battle(int numberOfEnemies, int level, Character* player)
{
	Player = player;
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
	while (Enemies.size() > 0 && !Player->GetIsDead())
	{
		std::cout << "Press any key to start the next round: " << std::endl;
		std::cout << "Round" << round << " starts:" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(WaitTime));
		TakeRound();
		round++;
	}
	EndBattle();
}

void Battle::EndBattle()
{
	if (Player->GetIsDead())
	{
		std::cout << "GAME OVER" << std::endl;
	}
	else
	{
		std::cout << "YOU DEFEATED YOUR ENEMIES." << std::endl;
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
			ActiveCharacter->Attack(Player);
		}
		else
		{
			int IndexToAttack = 0;
			while (IndexToAttack == i)
			{
				IndexToAttack = rand() % PlayerAndEnemies.size();
			}
			ActiveCharacter->Attack(PlayerAndEnemies[IndexToAttack]);
			if (PlayerAndEnemies[IndexToAttack]->GetIsDead())
			{
				Enemies.remove(PlayerAndEnemies[IndexToAttack]);
				AnEnemyDied = true;	
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(WaitTime));
	}
	if (AnEnemyDied)
	{
		PlayerAndEnemies.clear();
		FillPlayerAndEnemiesVector();
	}
}

void Battle::DecideInitiative()
{
	// Set initiative for enemies
	int NewInitiative = rand() % 20 + 1;
	for (Character* Character : Enemies)
	{
		NewInitiative = NewInitiative + Character->GetBaseInitiative();
		Character->SetInitiative(NewInitiative);
		NewInitiative = rand() % 20 + 1;
	}

	// Set initiative for player
	NewInitiative = NewInitiative + Player->GetBaseInitiative();
	Player->SetInitiative(NewInitiative);
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
	PlayerAndEnemies.push_back(Player);
	for (Character* Character : Enemies)
	{
		PlayerAndEnemies.push_back(Character);
	}
}

void Battle::ShowEnemies()
{

}

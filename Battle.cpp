#include "Battle.h"
#include "Enemy.h"
#include <list>

Battle::Battle(int numberOfEnemies, int level, Character* player)
{
	Player = player;
	int Index = 0;
	while (Index < numberOfEnemies)
	{
		Character EnemyObject = Enemy(level);
		Character* Enemy = &EnemyObject;
		Enemies.push_back(Enemy);
		Index++;
	}
}

void Battle::StartBattle()
{
}

void Battle::TakeTurn()
{
	DecideInitiative();
	FillPlayerAndEnemiesVector();
	DecideOrderForBattle();
	for (int i = 0; i < PlayerAndEnemies.size(); i++)
	{
		Character* ActiveCharacter = PlayerAndEnemies[i];
		if (static_cast<Enemy*>(ActiveCharacter))
		{
			ActiveCharacter->Attack(Player);
		}
		else
		{
			int IndexToAttack = 0;
			while (IndexToAttack != i)
			{
				IndexToAttack = rand() % PlayerAndEnemies.size();
			}
			ActiveCharacter->Attack(PlayerAndEnemies[IndexToAttack]);
			if (PlayerAndEnemies[IndexToAttack]->GetIsDead())
			{
				Enemies.remove(PlayerAndEnemies[IndexToAttack]);
			}
		}
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

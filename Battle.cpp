#include "Battle.h"
#include "Character.h"

void Battle::TakeTurn()
{

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

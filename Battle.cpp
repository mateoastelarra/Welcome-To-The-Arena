#include "Battle.h"
#include "Character.h"

void Battle::TakeTurn()
{

}

void Battle::DecideInitiative()
{
	int NewInitiative = rand() % 20 + 1;
	for (Character* Character : Enemies)
	{
		NewInitiative = NewInitiative + Character->GetBaseInitiative();
		Character->SetInitiative(NewInitiative);
		NewInitiative = rand() % 20 + 1;
	}
}

void Battle::DecideOrderForBattle()
{

}

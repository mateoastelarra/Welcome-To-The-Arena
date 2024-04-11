#include <iostream>
#include <list>

class Character;

class Battle
{
public:
	Battle();

private:
	int NumberOfEnemies;
	std::list<Character*> Enemies;
	Character* Player;

public:
	void TakeTurn();
	void DecideInitiative();
	void DecideOrderForBattle();
};
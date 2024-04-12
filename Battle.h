#include <iostream>
#include <list>
#include <vector>

class Character;

class Battle
{
public:
	Battle();

private:
	int NumberOfEnemies;
	class std::list<Character*> Enemies;
	class std::vector<Character*> PlayerAndEnemies;
	Character* Player;

public:
	void TakeTurn();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
};
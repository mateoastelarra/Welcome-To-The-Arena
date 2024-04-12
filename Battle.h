#include <iostream>
#include <list>
#include <vector>

class Character;

class Battle
{
public:
	Battle(int numberOfEnemies, int level, Character* player);

private:
	std::list<Character*> Enemies;
	std::vector<Character*> PlayerAndEnemies;
	Character* Player;

public:
	void StartBattle();
	void TakeTurn();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
};
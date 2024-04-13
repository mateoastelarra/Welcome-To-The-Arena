#include <iostream>
#include <list>
#include <vector>

class Character;
class Enemy;

class Battle
{
public:
	Battle(int numberOfEnemies, int level, Character* player);
	~Battle();
private:
	std::list<Character*> Enemies;
	std::vector<Character*> PlayerAndEnemies;
	Character* Player;

public:
	void StartBattle();
	void EndBattle();
	void TakeTurn();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
	void ShowEnemies();
};
#include <iostream>
#include <list>
#include <vector>

class Character;
class Enemy;

class Battle
{
public:
	Battle(int numberOfEnemies, int level, Character* player, Enemy* enemy);

private:
	std::list<Character*> Enemies;
	std::list<Enemy*> RealEnemies;
	std::vector<Character*> PlayerAndEnemies;
	Character* Player;

public:
	Enemy* AuxEnemy;
	void StartBattle();
	void TakeTurn();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
	void ShowEnemies();
};
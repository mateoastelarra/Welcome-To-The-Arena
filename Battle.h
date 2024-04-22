#pragma once
#include <iostream>
#include <list>
#include <vector>

class Character;
class Player;
//class Enemy;

class Battle
{
public:
	Battle(int numberOfEnemies, int level, Player* player);
	~Battle();
private:
	std::list<Character*> Enemies;
	std::vector<Character*> PlayerAndEnemies;
	Player* CurrentPlayer;

	// Time between each character turn
	int WaitTime = 2;
	bool CheckDeaths();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
	void ResetDefenses();
	void TakeRound();

public:
	void StartBattle();
	void EndBattle();
	void ShowEnemies();
	
};
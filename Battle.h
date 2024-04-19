#pragma once
#include <iostream>
#include <list>
#include <vector>

class Character;
//class Enemy;

class Battle
{
public:
	Battle(int numberOfEnemies, int level, Character* player);
	~Battle();
private:
	std::list<Character*> Enemies;
	std::vector<Character*> PlayerAndEnemies;
	class Player* CurrentPlayer;

	// Time between each character turn
	int WaitTime = 2;

public:
	void StartBattle();
	void EndBattle();
	void TakeRound();
	void DecideInitiative();
	void DecideOrderForBattle();
	void FillPlayerAndEnemiesVector();
	void ShowEnemies();
};
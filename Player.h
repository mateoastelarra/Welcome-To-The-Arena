#pragma once
#include "Character.h"
#include <list>

class Player : public Character
{
public:
	Player(int level);
	void ImprovePlayer();
	void LevelUp();
	void TakeTurn(std::list<Character*> Characters);

private:
	std::string ChooseCharacteristic(std::vector<std::string> Characteristics, std::string Characteristic);
	std::string ChooseName();
	void PlayerAttack(std::list<Character*> Characters);
};


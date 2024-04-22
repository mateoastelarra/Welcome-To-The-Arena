#pragma once
#include "Character.h"
#include <list>

class Player : public Character
{
public:
	Player(int level);
	void ImprovePlayer();
	void LevelUp();
	void TakeTurn(Character* Other, std::list<Character*> Characters);

private:
	std::string ChooseCharacteristic(std::vector<std::string> Characteristics, std::string Characteristic);
	std::string ChooseName();
};


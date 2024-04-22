#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(int level);
	void ImprovePlayer();
	void LevelUp();
	void TakeTurn(Character* Other, std::vector<Character*> Characters);

private:
	std::string ChooseCharacteristic(std::vector<std::string> Characteristics, std::string Characteristic);
	std::string ChooseName();
};


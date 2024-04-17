#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();

private:
	std::string ChooseCharacteristic(std::vector<std::string> Charasteristics, std::string Characteristic);
};


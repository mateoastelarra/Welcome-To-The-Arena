#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(int level);

private:
	int BaseHitpoints = 10;
	int BaseStrength = 10;
	int BaseArmor = 10;
	int BaseInteligence = 10;
	std::vector<std::string> Names = { "William", "Joe", "Argos", "Anna", "Julia", "Karen", "Michael", "Robert", "Walter", "Kate", "Leo", "Cristina" };
};


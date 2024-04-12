#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(int level);

private:
	int BaseHitpoints = 5;
	int BaseStrength;
	int BaseArmor;
	int BaseInteligence;
	std::vector<std::string> Names = {"William", "Joe", "Argos", "Anna", "Julia", "Karen", "Michael", "Robert", "Walter", "Kate", "Leo", "Cristina"};
};


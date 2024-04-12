#include "Enemy.h"

Enemy::Enemy(int level):Character()
{
	Level = level;
	Name = Name[rand() % Names.size()];
	Class = Classes[rand() % Classes.size()];
	Race = Races[rand() % Races.size()];
	HitPoints = BaseHitpoints + (rand() % 3 + 1) * level;
	Strength = BaseStrength + (rand() % 3 + 1) * level;
	Armor = BaseArmor + (rand() % 3 + 1) * level;
	Inteligence = BaseInteligence + (rand() % 3 + 1) * level;
	BaseInitiative = (rand() % 3) * level;
}

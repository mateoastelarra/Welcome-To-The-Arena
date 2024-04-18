#include "Enemy.h"
#include "Helpers.h"

Enemy::Enemy(int level) : Character()
{
	Level = level;
	Name = Helpers::Names[rand() % Helpers::Names.size()];
	Class = Helpers::Classes[rand() % Helpers::Classes.size()];
	Race = Helpers::Races[rand() % Helpers::Races.size()];

	SetBaseStatsByClass(Class);
	HitPoints = BaseHitpoints + (rand() % 3 + 1) * level;
	Strength = BaseStrength + (rand() % 3 + 1) * level;
	Armor = BaseArmor + (rand() % 3 + 1) * level;
	Inteligence = BaseInteligence + (rand() % 3 + 1) * level;
	BaseInitiative = (rand() % 3) * level;
}

#include "Character.h"



Character::Character(std::string CharacterClass, 
					 std::string Race, 
					 int HitPoints, 
					 int Strength, 
					 int Armor, 
					 int Initiative, 
					 int Inteligence, 
					 int Level)
{
	CharacterClass = CharacterClass;
	Race = Race;
	HitPoints = HitPoints;
	Strength = Strength;
	Armor = Armor;
	Initiative = Initiative;
	Inteligence = Inteligence;
	Level = Level;
}

void Character::Attack()
{
}

void Character::Defend()
{
}

void Character::SpecialArt()
{
}

void Character::Die()
{
}

void Character::TakeDamage()
{
}

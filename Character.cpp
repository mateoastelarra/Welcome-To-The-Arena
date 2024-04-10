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
	this->Class = CharacterClass;
	this->Race = Race;
	this->HitPoints = HitPoints;
	this->Strength = Strength;
	this->Armor = Armor;
	this->Initiative = Initiative;
	this->Inteligence = Inteligence;
	this->Level = Level;
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

void Character::ShowStats()
{
	std::cout << "Your Player is an " << Race << " " << Class << " With these stats:" << std::endl;
	std::cout << "HitPoints: " << HitPoints << " - ";
	std::cout << "Strength: " << Strength << " - ";
	std::cout << "Armor: " << Armor << " - ";
	std::cout << "Initiative: " << Initiative << " - ";
	std::cout << "Inteligence: " << Inteligence << " - ";
	std::cout << "Level: " << Level <<std::endl;
}

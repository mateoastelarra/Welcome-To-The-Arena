#include "Character.h"
#include <cmath>

Character::Character()
{
}

Character::Character(std::string Name,
					 std::string CharacterClass, 
					 std::string Race, 
					 int HitPoints, 
					 int Strength, 
					 int Armor,
					 int BaseInitiative, 
					 int Inteligence, 
					 int Level)
{
	this->Name = Name;
	this->Class = CharacterClass;
	this->Race = Race;
	this->HitPoints = HitPoints;
	this->Strength = Strength;
	this->Armor = Armor;
	this->BaseInitiative = Initiative;
	this->Initiative = 0;
	this->Inteligence = Inteligence;
	this->Level = Level;
}

void Character::Attack(Character* other)
{
	std::cout << Name << " attacks " << other->GetName() << ":" << std::endl;
	int Damage = rand() % 20 + 1;
	Damage = fmax(Damage + Strength - other->GetArmor(), 0);

	if (Damage > 0)
	{
		std::cout <<"Makes " << Damage << " Damage." << std::endl;
	}
	else
	{
		std::cout << "Misses the hit. " << other->GetName() << " Gets no Damage." << std::endl;
	}
	other->TakeDamage(Damage);
}

void Character::Defend()
{
}

void Character::SpecialArt()
{
}

void Character::Die()
{
	std::cout << Name << " Is now Dead" << std::endl;
}

void Character::TakeDamage(int damage)
{
	HitPoints -= damage;
	if (HitPoints <= 0)
	{
		HitPoints = 0;
		Die();
	}
}

void Character::ShowStats()
{
	std::cout << Name << " is an " << Race << " " << Class << " With these stats:" << std::endl;
	std::cout << "HitPoints: " << HitPoints << " - ";
	std::cout << "Strength: " << Strength << " - ";
	std::cout << "Armor: " << Armor << " - ";
	std::cout << "Initiative: " << BaseInitiative << " - ";
	std::cout << "Inteligence: " << Inteligence << " - ";
	std::cout << "Level: " << Level <<std::endl;
}

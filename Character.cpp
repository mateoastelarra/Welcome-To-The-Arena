#include "Character.h"



Character::Character(std::string Name,
					 std::string CharacterClass, 
					 std::string Race, 
					 int HitPoints, 
					 int Strength, 
					 int Armor, 
					 int Initiative, 
					 int Inteligence, 
					 int Level)
{
	this->Name = Name;
	this->Class = CharacterClass;
	this->Race = Race;
	this->HitPoints = HitPoints;
	this->Strength = Strength;
	this->Armor = Armor;
	this->Initiative = Initiative;
	this->Inteligence = Inteligence;
	this->Level = Level;
}

void Character::Attack(Character* other)
{
	int Damage = rand() % 20 + 1;
	Damage = Damage + Strength - other->GetArmor();
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
	std::cout << Name << "Is now Dead" << std::endl;
}

void Character::TakeDamage(int damage)
{
	HitPoints -= damage;
	if (HitPoints < 0)
	{
		Die();
	}
}

void Character::ShowStats()
{
	std::cout << Name << " is an " << Race << " " << Class << " With these stats:" << std::endl;
	std::cout << "HitPoints: " << HitPoints << " - ";
	std::cout << "Strength: " << Strength << " - ";
	std::cout << "Armor: " << Armor << " - ";
	std::cout << "Initiative: " << Initiative << " - ";
	std::cout << "Inteligence: " << Inteligence << " - ";
	std::cout << "Level: " << Level <<std::endl;
}

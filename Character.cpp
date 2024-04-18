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
	this->Initiative = 0;
	this->BaseInitiative = Initiative;
	this->Inteligence = Inteligence;
	this->Level = Level;
}

void Character::Attack(Character* other)
{
	if (IsDead or other->GetIsDead()) { return; }

	std::cout << Name << " the " << Race << " attacks " << other->GetName() << ":" << std::endl;
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
	std::cout << Name << " the " << Class << " Is now Dead" << std::endl;
	IsDead = true;
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

void const Character::ShowStats()
{
	std::cout << Name << " is a " << Race << " " << Class << " with these stats:" << std::endl;
	std::cout << "HitPoints: " << HitPoints << " - ";
	std::cout << "Strength: " << Strength << " - ";
	std::cout << "Armor: " << Armor << " - ";
	std::cout << "Initiative: " << BaseInitiative << " - ";
	std::cout << "Inteligence: " << Inteligence << " - ";
	std::cout << "Level: " << Level <<std::endl;
}

void Character::SetBaseStatsByClass(std::string AClass)
{
	if (AClass == "Warrior")
	{
		BaseHitpoints = 13;
		BaseStrength = 12;
		BaseArmor = 10;
		BaseInteligence = 2;
	}
	else if (AClass == "Wizard")
	{
		BaseHitpoints = 9;
		BaseStrength = 8;
		BaseArmor = 9;
		BaseInteligence = 16;
	}
	else if (AClass == "Druid")
	{
		BaseHitpoints = 12;
		BaseStrength = 11;
		BaseArmor = 12;
		BaseInteligence = 7;
	}
	else if (AClass == "Palladin")
	{
		BaseHitpoints = 10;
		BaseStrength = 10;
		BaseArmor = 12;
		BaseInteligence = 10;
	}
}

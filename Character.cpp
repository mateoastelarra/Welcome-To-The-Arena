#include "Character.h"
#include "Helpers.h"
#include <cmath>


Character::Character()
{
}

void Character::Attack(Character* other)
{
	if (IsDead or other->GetIsDead()) { return; }

	std::cout << Name << " the " << Race << " attacks " << other->GetName() << ":" << std::endl;
	int Damage = rand() % 20 + 1;
	Damage = fmax(Damage + Strength - other->GetArmor(), 0);
	other->TakeDamage(Damage);
}

void Character::Defend()
{
	IsDefending = true;
	HitPoints += DefenseBonus;
	std::cout << Name << " the " << Race << " is defending and gains " << DefenseBonus << " hit points." << std::endl;
}

void Character::BreakDefense()
{
	if (IsDefending)
	{
		IsDefending = false;
		std::cout << Name << " the " << Race << " defense is broken." << std::endl;
	}
}

void Character::SpecialArt(std::list<Character*> others, std::string castingSpeech, int waitTime)
{
	std::cout << "Casting Special Art." << std::endl;
	Helpers::WaitForSeconds(waitTime);
	for (Character* other: others)
	{
		if (IsDead or other->GetIsDead()) { continue; }
		std::cout << Name << " the " << Race << castingSpeech << other->GetName() << ":" << std::endl;
		int Damage = rand() % 20 + 1;
		Damage = fmax(Damage + Inteligence - other->GetArmor(), 0);
		other->TakeDamage(Damage);
	}
}

void Character::Die()
{
	std::cout << Name << " the " << Race << " Is now Dead" << std::endl;
	IsDead = true;
}

void Character::TakeDamage(int damage)
{
	if (IsDefending)
	{
		std::cout << Name << " is defending." << std::endl;
		HitPoints -= fmax(damage - Armor, 0);
		std::cout << "Makes " << fmax(damage - Armor, 0) << " damage." << std::endl;
	}
	else if (damage > 0)
	{
		std::cout << "Makes " << damage << " damage." << std::endl;
		HitPoints -= damage;
	}
	else
	{
		std::cout << "Misses the hit. " << Name << " Gets no damage." << std::endl;
	}
	
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
		SpecialArtSpeech = " shouts with might and throws a punch at ";
	}
	else if (AClass == "Wizard")
	{
		BaseHitpoints = 9;
		BaseStrength = 8;
		BaseArmor = 9;
		BaseInteligence = 16;
		SpecialArtSpeech = " throws a fireball and impacts ";
	}
	else if (AClass == "Druid")
	{
		BaseHitpoints = 12;
		BaseStrength = 11;
		BaseArmor = 12;
		BaseInteligence = 12;
		SpecialArtSpeech = " turns into a wolf and attacks ";

	}
	else if (AClass == "Palladin")
	{
		BaseHitpoints = 10;
		BaseStrength = 10;
		BaseArmor = 12;
		BaseInteligence = 9;
		SpecialArtSpeech = " fills the sword with faith and attacks ";
	}
}

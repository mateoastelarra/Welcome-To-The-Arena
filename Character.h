#include <iostream>

class Character
{
public:
	Character(std::string CharacterClass,
			  std::string Race,
			  int HitPoints,
			  int Strength,
			  int Armor,
			  int Initiative,
			  int Inteligence,
			  int Level);

protected:
	std::string CharacterClass;
	std::string Race;
	int HitPoints;
	int Strength;
	int Armor;
	int Initiative;
	int Inteligence;
	int Level;

public:
	void Attack();
	void Defend();
	void SpecialArt();
	void Die();
	void TakeDamage();

};
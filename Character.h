#include <iostream>

class Character
{
public:
	Character(std::string Name,
			  std::string CharacterClass,
			  std::string Race,
			  int HitPoints,
			  int Strength,
			  int Armor,
			  int Initiative,
			  int Inteligence,
			  int Level);

protected:
	std::string Name;
	std::string Class;
	std::string Race;
	int HitPoints;
	int Strength;
	int Armor;
	int Initiative;
	int Inteligence;
	int Level;

public:

	//Getters
	std::string const GetName() { return Name; }
	std::string const GetClass() { return Class; }
	std::string const GetRace() { return Race; }
	int const GetHP() { return HitPoints; }
	int const GetStrength() { return Strength; }
	int const GetArmor() { return Armor; }
	int const GetInitiative() { return Initiative; }
	int const GetInteligence() { return Inteligence; }
	int const GetLevel() { return Level; }

	// Other methods
	void Attack(Character* other);
	void Defend();
	void SpecialArt();
	void Die();
	void TakeDamage(int damage);
	void ShowStats();

};
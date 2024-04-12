#include <iostream>
#include <vector>

class Character
{
public:
	Character();
	Character(std::string Name,
			  std::string Class,
			  std::string Race,
			  int HitPoints,
			  int Strength,
			  int Armor,
			  int BaseInitiative,
			  int Inteligence,
			  int Level);

protected:
	std::string Name;
	std::string Class;
	std::string Race;
	int HitPoints;
	int Strength;
	int Armor;
	int BaseInitiative;
	int Initiative;
	int Inteligence;
	int Level;

	std::vector<std::string> Classes = { "Warrior", "Wizard", "Druid", "Palladin" };
	std::vector<std::string> Races = { "Elf", "Human", "Dwarf", "Halfling", "Orc", "Goblin" };

public:

	//Getters
	std::string const GetName() { return Name; }
	std::string const GetClass() { return Class; }
	std::string const GetRace() { return Race; }
	int const GetHP() { return HitPoints; }
	int const GetStrength() { return Strength; }
	int const GetArmor() { return Armor; }
	int const GetBaseInitiative() { return BaseInitiative; }
	int const GetInitiative() { return Initiative; }
	int const GetInteligence() { return Inteligence; }
	int const GetLevel() { return Level; }

	// Setters
	void SetInitiative(int initiative) { Initiative = initiative; }

	// Other methods
	void Attack(Character* other);
	void Defend();
	void SpecialArt();
	void Die();
	void TakeDamage(int damage);
	void ShowStats();

};
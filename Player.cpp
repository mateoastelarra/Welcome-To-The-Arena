#include "Player.h"
#include "Helpers.h"
#include <conio.h> // For _kbhit and _getch

Player::Player(int level) : Character()
{
    Name = ChooseName();
	Class = ChooseCharacteristic(Helpers::Classes, "class");
	Race = ChooseCharacteristic(Helpers::Races, "race");

    SetBaseStatsByClass(Class);
    Level = level;
    MaxHitPoints = BaseHitpoints + (rand() % 5 + 2) * Level;
    HitPoints = MaxHitPoints;
    Strength = BaseStrength + (rand() % 5 + 2) * Level;
    Armor = BaseArmor + (rand() % 5 + 2) * Level;
    Inteligence = BaseInteligence + (rand() % 5 + 2) * Level;
    BaseInitiative = (rand() % 5) * Level;
    DefenseBonus = fmax((Armor + Inteligence) / 6, 1);

}

void Player::ImprovePlayer()
{
    while (true)
    {
        std::cout << "The Battle is over, what do you want to Improve?" << std::endl;
        std::vector<std::string> Options = { "Max Hit Points", "Strength", "Armor", "Inteligence", "Initiative" };
        std::vector<int*> Stats = { &MaxHitPoints, &Strength, &Armor, &Inteligence, &BaseInitiative };
        for (int i = 0; i < Options.size(); i++)
        {
            std::cout << i + 1 << ")" << Options[i] << ". Current = " << *Stats[i] <<  std::endl;
        }
        int ChosenItemIndex = _getch() - '0' - 1; // Because it returns ascII code and vector starts in 0

        if (ChosenItemIndex >= 0 && ChosenItemIndex < Options.size())
        {
            *Stats[ChosenItemIndex] += (rand() % 4 + 1);
            std::cout << "Congrats!!" << std::endl;
            std::cout << "Your " << Options[ChosenItemIndex] << " is now " << *Stats[ChosenItemIndex] << std::endl;
            return;
        }
        else
        {
            std::cout << "Please choose a valid option " << Name << std::endl;
        }
    }
}

void Player::LevelUp()
{
    IsDead = false;
    Level += 1;
    MaxHitPoints += (rand() % 3 + 1) * Level;
    HitPoints = MaxHitPoints;
    Strength += (rand() % 3 + 2) * Level;
    Armor += (rand() % 3 + 2) * Level;
    Inteligence += (rand() % 3 + 2) * Level;
    BaseInitiative += (rand() % 3 + 2) * Level;
    DefenseBonus += (rand() % 3 + 2) * Level;
}

void Player::TakeTurn(std::list<Character*> Characters)
{ 
    if (IsDead) { return; }
    int ChosenItemIndex;
    while (true)
    {
        std::cout << "Your turn has come " << Name << ". What do you want to do? " << std::endl;
        std::cout << "1) Attack. " << std::endl;
        std::cout << "2) Defend. " << std::endl;
        std::cout << "3) Special Art. " << std::endl;

        ChosenItemIndex = _getch() - '0'; // Because it returns ascII code and want exact option
        if (ChosenItemIndex > 0 && ChosenItemIndex < 4)
        {
            break;
        }
        else
        {
            std::cout << "Please choose a valid option " << Name << std::endl;
        }
    } 

    switch (ChosenItemIndex)
    {
        case 1:
            PlayerAttack(Characters);
            break;
        case 2:
            Defend();
            break;
        case 3:
            SpecialArt(Characters, SpecialArtSpeech, 1);
            break;
    }
}

std::string Player::ChooseCharacteristic(std::vector<std::string> Charasteristics, std::string Characteristic)
{
    while (true)
    {
        std::cout << "Choose a " << Characteristic << " for your player using the numbers: " << std::endl;
        for (int i = 0; i < Charasteristics.size(); i++)
        {
            std::cout << i + 1 << ")" << Charasteristics[i] << "." << std::endl;
        }
        int ChosenItemIndex = _getch() - '0' - 1; // Because it returns ascII code and vector starts in 0

        if (ChosenItemIndex >= 0 && ChosenItemIndex < Charasteristics.size())
        {
            return Charasteristics[ChosenItemIndex];
        }
        else
        {
            std::cout << "Please choose a valid option "<< Name << std::endl;
        }
    }
}

std::string Player::ChooseName()
{
    std::cout << "I am a console god. Please choose your name and press enter." << std::endl;
    std::string PlayerName;
    std::cin >> PlayerName;

    return PlayerName;
}

void Player::PlayerAttack(std::list<Character*> Characters)
{
    std::cout << "Who do you want to attack?" << std::endl;

    std::vector<Character*> Enemies;
    for (Character* character : Characters)
    {
        Enemies.push_back(character);
    }

    
    for (int i = 0; i < Enemies.size(); i++)
    {
        std::cout << i + 1 << ")" << Enemies[i]->GetName() << " the " << Enemies[i]->GetRace() << " has " << Enemies[i]->GetHP() << " hit points." << std::endl;
    }

    int ChosenItemIndex = _getch() - '0' - 1; // Because it returns ascII code and vector starts in 0
    Attack(Enemies[ChosenItemIndex]);
}

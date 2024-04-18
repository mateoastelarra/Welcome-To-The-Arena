#include "Player.h"
#include "Helpers.h"
#include <conio.h> // For _kbhit and _getch

Player::Player(int level) : Character()
{
	Helpers::AskYesOrNoQuestion("Hello Traveller. Are you ready to fight in the Arena?");
    Name = ChooseName();
	Class = ChooseCharacteristic(Helpers::Classes, "class");
	Race = ChooseCharacteristic(Helpers::Races, "race");

    SetBaseStatsByClass(Class);
    Level = level;
    HitPoints = BaseHitpoints + (rand() % 5 + 2) * Level;
    Strength = BaseStrength + (rand() % 5 + 2) * Level;
    Armor = BaseArmor + (rand() % 5 + 2) * Level;
    Inteligence = BaseInteligence + (rand() % 5 + 2) * Level;
    BaseInitiative = (rand() % 5) * Level;

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
        int ChosenItemIndex = _getch() - '0' - 1; // Because it returns ascII code

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

#include "Player.h"
#include "Helpers.h"
#include <conio.h> // For _kbhit and _getch

Player::Player() : Character()
{
	Helpers::AskYesOrNoQuestion("Hello Traveller. Are you ready to fight in the Arena?");
	Name = ChooseCharacteristic(Helpers::Names, "Name");
	Class = ChooseCharacteristic(Helpers::Classes, "Class");
	Race = ChooseCharacteristic(Helpers::Races, "Race");
}

std::string Player::ChooseCharacteristic(std::vector<std::string> Charasteristics, std::string Characteristic)
{
    while (true)
    {
        std::cout << "Choose a " << Characteristic << " for your player using the numbers : " << std::endl;
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
            std::cout << "Please Choose a valid option traveller" << std::endl;
        }
    }
}

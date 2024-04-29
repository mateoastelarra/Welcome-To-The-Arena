#include "Helpers.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <conio.h> // For _kbhit and _getch


const std::vector<std::string> Helpers::Classes = { "Warrior", "Wizard", "Druid", "Palladin" };
const std::vector<std::string> Helpers::Races = { "Elf", "Human", "Dwarf", "Halfling", "Orc", "Goblin" };
const std::vector<std::string> Helpers::Names = { "William", "Joe", "Argos", "Anna", "Julia", "Karen", "Michael", "Robert", "Walter", "Kate", "Leo", "Cristina" };

void Helpers::ClearWindow()
{
    system("cls");
}

void Helpers::WaitForSeconds(int Seconds)
{
	std::this_thread::sleep_for(std::chrono::seconds(Seconds));
}

void Helpers::WaitForPlayerResponse(std::string SpecialText)
{
    std::cout << "Press any key " << SpecialText << "..." << std::endl;
    while (!_kbhit()) // Wait until a key is pressed
    {
        // Do nothing, just wait
    }
    _getch(); // Clear the key from the input buffer
}

bool Helpers::AskYesOrNoQuestion(std::string SpecialText)
{
    std::cout << SpecialText << std::endl;
    while (true)
    {
        std::cout << "Enter y for yes or n for no." << std::endl;
        char UserInput;
        UserInput = _getch();

        if (UserInput == 'y')
        {
            return true;
        }
        else if (UserInput == 'n')
        {
            return false;
        }
    }
    
}

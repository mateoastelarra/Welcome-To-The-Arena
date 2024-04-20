// WelocomeToTheArena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
//#include "Enemy.h"
#include "Battle.h"
#include "Player.h"
#include "Helpers.h"

int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    
    bool WantToPlay = Helpers::AskYesOrNoQuestion("Hello Traveller. Are you ready to fight in the Arena?");
    bool KeepCharacter = false;
    Player* PlayerPtr = nullptr;
    Battle* NewBattle = nullptr;

    while (WantToPlay)
    {
        if (!KeepCharacter)
        {
            PlayerPtr = new Player(1);
        }
        else
        {
            PlayerPtr->LevelUp();
        }
       
        int NumberOfEnemies = 1;
        while (PlayerPtr->GetIsDead() == false)
        {
            std::cout << "Battle number " << NumberOfEnemies << std::endl;
            NewBattle = new Battle(NumberOfEnemies, 1, PlayerPtr);
            NumberOfEnemies++;
        }

        WantToPlay = Helpers::AskYesOrNoQuestion("Do you want to play again?");
        KeepCharacter = Helpers::AskYesOrNoQuestion("Do you want to continue with this character and gain a level?");
    }
    // Deallocate memory for dynamically allocated objects
    if (PlayerPtr != nullptr)
        delete PlayerPtr;
    
    
    if (NewBattle != nullptr)
        delete NewBattle;
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// WelocomeToTheArena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Enemy.h"
#include "Battle.h"

int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    Character PlayerObject = Character("Juan", "Warrior", "Elf", 10, 13, 17, 3, 10, 1);
    Character* PlayerPtr = &PlayerObject;

    Enemy EnemyObject = Enemy(1);
    Enemy* enemy = &EnemyObject;

    //std::cout << enemy->GetName() << std::endl;

    Battle BattleObject = Battle(1, 1, PlayerPtr, enemy);
    //Battle* NewBattle = &BattleObject;
    //PlayerPtr->ShowStats();
    Enemy EnemyAux = Enemy(1);
    //PlayerPtr->Attack(&EnemyAux);
    //EnemyAux.Attack(PlayerPtr);
    //BattleObject.ShowEnemies();
    //BattleObject.AuxEnemy->ShowStats();
    BattleObject.TakeTurn();

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

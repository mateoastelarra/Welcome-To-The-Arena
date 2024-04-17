#include "Helpers.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h> // For _kbhit and _getch

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

#pragma once
#include <string>
#include <vector>

class Helpers
{
public:
	static void WaitForSeconds(int Seconds);
	static void WaitForPlayerResponse(std::string SpecialText);
	static bool AskYesOrNoQuestion(std::string SpecialText);
	static const std::vector<std::string> Classes;
	static const std::vector<std::string> Races;
	static const std::vector<std::string> Names;
};


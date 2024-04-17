#include "Player.h"
#include "Helpers.h"

Player::Player() : Character()
{
	Helpers::AskYesOrNoQuestion("Are you a Player?");
}

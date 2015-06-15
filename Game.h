#pragma once
#include "Player.h"
#include "PlayerCPU.h"
#include "PlayerHuman.h"
#include "Board.h"

class Game
{
private:
	PlayerHuman humanPlayer;
	PlayerCPU cpuPlayer;
	Board board;
public:
	Game();
	void start();
};

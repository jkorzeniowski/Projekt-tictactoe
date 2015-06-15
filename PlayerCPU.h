#pragma once
#include "Player.h"

class PlayerCPU : public Player
{
public:
	PlayerCPU();
	PlayerCPU(enum figures figure);
	virtual int chooseSubgrid(Board board);
	virtual int makeMove(Board board);
	virtual enum figures getFigure();
};

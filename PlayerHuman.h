#pragma once
#include "Player.h"

class PlayerHuman : public Player
{
public:
	PlayerHuman();
	PlayerHuman(enum figures figure);
	virtual int chooseSubgrid(Board board);
	virtual int makeMove(Board board);
	virtual enum figures getFigure();
};

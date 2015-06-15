#pragma once
#include "Board.h"

//Base abstract class
//abstract because has pure virtual function move()
class Player
{
protected:
	enum figures figure;
public:
	virtual int chooseSubgrid(Board board) = 0; // do tych instancji nie mozna sie odwolac!
	virtual int makeMove(Board currentBoard) = 0;
	virtual enum figures getFigure() = 0;
};

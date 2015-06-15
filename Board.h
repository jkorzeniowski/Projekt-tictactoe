#pragma once
#include <stdio.h>

enum figures {
	nothing = '-',
	cross = 'x',
	circle = 'o'
};

class Board
{
private:
	enum figures grid[9][9];
	int currentSubgrid;
public:
	Board();
	void show();
	bool play(int space, enum figures figure);
	int getCurrentSubgrid();
	void switchSubgrid(int newSubgrid);
	enum figures whoWonGrid();
	bool isGridWon();
	enum figures whoWonSubgrid(int subgrid);
	bool isSubgridWon(int subgrid);
};

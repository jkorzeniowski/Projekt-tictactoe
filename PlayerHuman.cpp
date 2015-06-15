#include "PlayerHuman.h"
#include <iostream>
using namespace std;

PlayerHuman::PlayerHuman(enum figures newFigure) {
	figure = newFigure;
}

PlayerHuman::PlayerHuman() {
	figure = circle;
}

int PlayerHuman::makeMove(Board currentBoard) {
	printf("Aktualny subgrid: %i\n", currentBoard.getCurrentSubgrid());
	printf("Wybierz pole w tym subgrid: ");
	int space = 0;
	cin >> space;
	printf("\n");
	return space;
}

enum figures PlayerHuman::getFigure()
{
	return figure;
}

int PlayerHuman::chooseSubgrid(Board currentBoard) {
	printf("Wybierz subgrid: ");
	int subgrid = 0;
	cin >> subgrid;
	printf("\n");
	return subgrid;
}

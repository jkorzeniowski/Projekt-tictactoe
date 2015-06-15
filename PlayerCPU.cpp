#include "PlayerCPU.h"
#include <stdlib.h>

PlayerCPU::PlayerCPU() {
	figure = cross;
}

PlayerCPU::PlayerCPU(enum figures newFigure) {
	figure = newFigure;
}

int PlayerCPU::makeMove(Board currentBoard) {
	int subgrid = currentBoard.getCurrentSubgrid();
	int mark = rand() % 9;
	printf("CPU makes move: %i:%i\n", subgrid, mark);
	return mark;
}

enum figures PlayerCPU::getFigure()
{
	return figure;
}

int PlayerCPU::chooseSubgrid(Board currentBoard) {
    printf("Aktualny subgrid: %i jest juz zwyciezony\n", currentBoard.getCurrentSubgrid());
	printf("Wybierz inny subgrid: ");
	int subgrid = rand() % 9;
	printf("CPU chooses subgrid: %i\n", subgrid);
	return subgrid;
}

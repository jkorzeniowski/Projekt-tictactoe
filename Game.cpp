#include "Game.h"

Game::Game()
{
	board = Board();
	humanPlayer = PlayerHuman(circle);
	cpuPlayer = PlayerCPU(cross);
}

void Game::start()
{
	//int currentPos = 0;
	int i = 0;
	board.show();
	printf("\n");
    board.switchSubgrid(humanPlayer.chooseSubgrid(board));
	while (!board.isGridWon()) {
		if (i % 2) {
			while (board.isSubgridWon(board.getCurrentSubgrid()))
				board.switchSubgrid(cpuPlayer.chooseSubgrid(board));
			while (!board.play(cpuPlayer.makeMove(board), cpuPlayer.getFigure()));
		}
		else {
			while (board.isSubgridWon(board.getCurrentSubgrid()))
				board.switchSubgrid(humanPlayer.chooseSubgrid(board));
			while (!board.play(humanPlayer.makeMove(board), humanPlayer.getFigure()));
		}
		board.show();
		printf("\n");
		i++;
	}

	printf("\nWYGRANA!\n");
	enum figures winningMark = board.whoWonGrid();
	if (winningMark == cpuPlayer.getFigure())
		printf("Gracz ktory wygral: CPU\n");
	else
		printf("Gracz ktory wygral: humanPlayer\n");

}


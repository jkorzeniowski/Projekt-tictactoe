#include "Board.h"
#include "PlayerHuman.h"
#include <iostream>

using namespace std;

Board::Board()
{
	for (int i = 0; i<(9 * 9); i++)
		grid[i / 9][i % 9] = nothing;

    /*printf("Wybierz subgrid: ");
    int starter;
    cin >> starter;
	currentSubgrid = starter;*/
    currentSubgrid = 0;
}

void Board::show()
{
	int a = -1, b = 9;
	for (int i = 0; i<81; i++, b++)
	{
		if (!(i % 3))	{ printf(" ");	a++;	b -= 3; }
		if (!(i % 9))	{ printf("\n"); a -= 3;	b += 3; }
		if (!(i % 27)) { printf("\n"); a += 3;	b -= 9; }

		printf("%c", grid[a][b]);
	}
}

bool Board::play(int space, enum figures figure)
{
	if (currentSubgrid >= 0 && grid[currentSubgrid][space] == nothing)
	{
		grid[currentSubgrid][space] = figure;
		currentSubgrid = space;
		return true;
	}
	else return false;
}

int Board::getCurrentSubgrid()
{
	return currentSubgrid;
}

void Board::switchSubgrid(int newSubgrid) {
	currentSubgrid = newSubgrid;
}

enum figures Board::whoWonSubgrid(int subgrid)
{
	//printf("\tchecking if subgrid %i is won...\n", subgrid);

	//HORIZONTAL
	//0 1 2
	if (grid[subgrid][0] == grid[subgrid][1] && grid[subgrid][0] == grid[subgrid][2] && grid[subgrid][0] != nothing)
    {
       // printf("GRID %i HORIZONTAL 0-1-2\n", subgrid);
        return grid[subgrid][0];
    }

	//3 4 5
	if ( grid[subgrid][3] == grid[subgrid][4] && grid[subgrid][3] == grid[subgrid][5] && grid[subgrid][3] != nothing)
    {
        //printf("GRID %i HORIZONTAL 3-4-5\n", subgrid);
        return grid[subgrid][3];
    }
	//6 7 8
	if (grid[subgrid][6] == grid[subgrid][7] && grid[subgrid][6] == grid[subgrid][8] && grid[subgrid][6] != nothing)
    {
        //printf("GRID %i HORIZONTAL 6-7-8\n", subgrid);
        return grid[subgrid][6];
    }

	//VERTICAL
	//0 3 6
	if (grid[subgrid][0] == grid[subgrid][3] && grid[subgrid][0] == grid[subgrid][6] && grid[subgrid][0] != nothing)
    {
        //printf("GRID %i VERTICAL 0-3-6\n", subgrid);
        return grid[subgrid][0] ;
    }	//1 4 7
	if (grid[subgrid][1] == grid[subgrid][4] && grid[subgrid][1] == grid[subgrid][7] && grid[subgrid][1] != nothing)
    {
        //printf("GRID %i VERTICAL 1-4-7\n", subgrid);
        return grid[subgrid][1];
    }	//2 5 8
	if (grid[subgrid][2] == grid[subgrid][5] && grid[subgrid][2] == grid[subgrid][8] && grid[subgrid][2] != nothing)
    {
        //printf("GRID %i VERTICAL 2-5-8\n", subgrid);
        return grid[subgrid][2];
    }
	//DIAGONAL
	//0 4 8
	if (grid[subgrid][0] == grid[subgrid][4] && grid[subgrid][0] == grid[subgrid][8] && grid[subgrid][0] != nothing)
    {
        //printf("GRID %i DIAGONAL 0-4-8\n", subgrid);
        return grid[subgrid][0];
    }	//2 4 6
	if (grid[subgrid][2] == grid[subgrid][4] && grid[subgrid][2] == grid[subgrid][6] && grid[subgrid][2] != nothing)
    {
        //printf("GRID %i DIAGONAL 2-4-6\n", subgrid);
        return grid[subgrid][2];
    }
	//printf("\tended checking, returning nothing...\n");
	return nothing;
}

bool Board::isSubgridWon(int subgrid)
{
	return whoWonSubgrid(subgrid) != nothing;
}

enum figures Board::whoWonGrid()
{
	//printf("\tchecking if grid is won...\n");

	//HORIZONTAL
	//0 1 2
	if (whoWonSubgrid(0) == whoWonSubgrid(1) && whoWonSubgrid(0) == whoWonSubgrid(2) && whoWonSubgrid(0) != nothing)
    {
        //printf("SUBGRID HORIZONTAL 0-1-2\n");
        return whoWonSubgrid(0);
    }

	//3 4 5
	if (whoWonSubgrid(3) == whoWonSubgrid(4) && whoWonSubgrid(3) == whoWonSubgrid(5) && whoWonSubgrid(3) != nothing)
    {
        //printf("SUBGRID HORIZONTAL 3-4-5\n");
        return whoWonSubgrid(3);
    }	//6 7 8
	if (whoWonSubgrid(6) == whoWonSubgrid(7) && whoWonSubgrid(6) == whoWonSubgrid(8) && whoWonSubgrid(6) != nothing)
    {
        //printf("SUBGRID HORIZONTAL 6-7-8\n");
        return whoWonSubgrid(6);
    }
	//VERTICAL
	//0 3 6
	if (whoWonSubgrid(0) == whoWonSubgrid(3) && whoWonSubgrid(0) == whoWonSubgrid(6) && whoWonSubgrid(0) != nothing)
    {
        //printf("SUBGRID VERTICAL 0-3-6\n");
        return whoWonSubgrid(0);
    }	//1 4 7
	if (whoWonSubgrid(1) == whoWonSubgrid(4) && whoWonSubgrid(1) == whoWonSubgrid(7) && whoWonSubgrid(1) != nothing)
    {
        //printf("SUBGRID VERTICAL 1-4-7\n");
        return whoWonSubgrid(1);
    }	//2 5 8
	if (whoWonSubgrid(2) == whoWonSubgrid(5) && whoWonSubgrid(2) == whoWonSubgrid(8) && whoWonSubgrid(2) != nothing)
    {
        //printf("SUBGRID VERTICAL 2-5-8\n");
        return whoWonSubgrid(2);
    }
	//DIAGONAL
	//0 4 8
	if (whoWonSubgrid(0) == whoWonSubgrid(4) && whoWonSubgrid(0) == whoWonSubgrid(8) && whoWonSubgrid(0) != nothing)
    {
        //printf("SUBGRID DIAGONAL 0-4-8\n");
        return whoWonSubgrid(0);
    }	//2 4 6
	if (whoWonSubgrid(2) == whoWonSubgrid(4) && whoWonSubgrid(2) == whoWonSubgrid(6) && whoWonSubgrid(2) != nothing)
    {
        //printf("SUBGRID DIAGONAL 2-4-6\n");
        return whoWonSubgrid(2);
    }
	//printf("\tended checking if grid is won, returning nothing...\n");
	return nothing;
}

bool Board::isGridWon()
{
	return whoWonGrid() != nothing;
}


#include <time.h>
#include "Game.h"
#include <stdlib.h>


int main()
{
	srand((unsigned int)time(NULL));

	Game game = Game();
	game.start();

	system("PAUSE");
	return 0;
}

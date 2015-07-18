#include "GameSystem.h"

int main(int argc, char * argv[])
{
	GameSystem system("Fun Quest", "bg.png"); //create the window admin object

	system.gameLoop(); //begin the game

	return 0;
}
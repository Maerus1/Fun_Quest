#include "GameSystem.h"


GameSystem::GameSystem(const char *windowName, const char * backgroundPath) //const char * to make it compatible with SDL parameters for CreateWindow and 
																			//CreateRenderer
{
	//create window, renderer, and the event for pollEvent
	window = SDL_CreateWindow(windowName, 200, 200, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mainEvent = new SDL_Event();
	bg = IMG_LoadTexture(renderer, backgroundPath); //create parameters to allow main.cpp customization of the game!
	
	//defines the size of the background image
	bgRect.w = 800;
	bgRect.h = 600;
	

	//player texture definition:
	player = IMG_LoadTexture(renderer, "dan.png");

	//dimensions:
	playerRect.x = 400;
	playerRect.y = 300;
	playerRect.h = 100;
	playerRect.w = 90;

	//cropping
	playerCrop.w = 35;
	playerCrop.h = 50;

	//to help manage the game loop
	quit = false; //define everything in the constructor!!!
	xPos = 0;
	yPos = 0; //saves the x and y position for the player and edits it on keypress
}


GameSystem::~GameSystem()
{	//destroy all pointers!
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(bg);
	if (mainEvent)
		delete mainEvent;
}

void GameSystem::gameLoop()
{
	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);
		//scan for movement...

		playerMovement();
		SDL_RenderCopy(renderer, bg, 0, &bgRect); //draws the bg image
		SDL_RenderCopy(renderer, player, &playerCrop, &playerRect); //draw the player sprite
		SDL_RenderPresent(renderer);

		if (mainEvent->type == SDL_QUIT)
			quit = true;
	}
}

void GameSystem::renderBackground()
{

}

void GameSystem::playerMovement()
{

	if (mainEvent->key.keysym.sym == SDLK_LEFT)
		playerRect.x -= 5;		
	if (mainEvent->key.keysym.sym == SDLK_UP)
		playerRect.y -= 5;	
	if (mainEvent->key.keysym.sym == SDLK_RIGHT)
		playerRect.x += 5;
	if (mainEvent->key.keysym.sym == SDLK_DOWN)
		playerRect.y += 5;
	if (mainEvent->type == SDL_KEYUP)
	{
		std::cout << "derp" << std::endl; //this function doesn't work right
		playerRect.x = playerRect.x;
		playerRect.y = playerRect.y;
	}
}

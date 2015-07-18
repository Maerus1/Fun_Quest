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
	
	//to help manage the game loop
	quit = false; //define everything in the constructor!!!
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

		SDL_RenderCopy(renderer, bg, 0, &bgRect); //draws the bg image
		
		SDL_RenderPresent(renderer);

		if (mainEvent->type == SDL_QUIT)
			quit = true;
	}
}

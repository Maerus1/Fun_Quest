#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
class GameSystem
{
public:
	GameSystem(const char *windowName, const char *backgroundPath);
	~GameSystem();

	void gameLoop();

	void renderBackground();

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event * mainEvent;
	SDL_Texture * bg;
	SDL_Rect bgRect;

	SDL_Texture * player; //put in the player png bitmap
	SDL_Rect playerRect; //define the size of player
	SDL_Rect playerCrop; //to crop the sprite sheet
	bool quit;
};


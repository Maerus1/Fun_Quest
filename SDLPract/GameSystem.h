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
	bool quit;
};


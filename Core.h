#pragma once
#include "Singletons.h"
#include "Timer.h"
#include "GameStateManager.h"
#include "TestScene.h"

class Core
{
public:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Renderer* gRenderer;

	bool init();

	void handleInput();
	void logic();
	void render();

	void gameLoop();

	void measureFPS();

	void free();

	Core(int,int);

private:
	SDL_Event e;
	bool quit;

	int frameCount;
	LTimer fpsTimer;

	GameStateManager GSM;

	SDL_Window* gWindow;



};


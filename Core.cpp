#include "Core.h"

Core::Core(int sW,int sH)
	:
	SCREEN_WIDTH(sW),
	SCREEN_HEIGHT(sH),
	e(),
	GSM(new TestScene(&gRenderer, GSM))
{
	gWindow = NULL;
	gRenderer = NULL;

	frameCount = 0;

	quit = false;

}

bool Core::init() 
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!");
	}

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

void Core::handleInput()
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		GSM.currState->handleInput(e);
	}
}

void Core::logic()
{
	GSM.currState->logic();
}

void Core::render()
{

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);
	//////////////////////////////////////////

	GSM.currState->render();
	//SDL_Rect rect = { 0,0,100,100 };
	//SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(gRenderer, &rect);


	/////////////////////////////////////////
	SDL_RenderPresent(gRenderer);

}


void Core::measureFPS()
{
	

	if (fpsTimer.getTicks() > 1000)
	{

		std::cout << "FPS: " << frameCount << std::endl;
		fpsTimer.start();
		frameCount = 0;
	}
	frameCount++;

}

void Core::gameLoop()
{
	if (!init())
	{
		printf("Failed to initialize!\n");
		return;
	}

	fpsTimer.start();

	while (!quit)
	{
		measureFPS();

		handleInput();
		logic();
		render();
	}

	free();
}

void Core::free()
{

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
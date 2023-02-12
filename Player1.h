#pragma once
#include "Texture.h"
struct Player1
{
	LTexture text;
	SDL_Rect rect;
	int posX;
	int posY;
	int vel;
	int player;

	Player1(SDL_Renderer*);
	void handleInput(SDL_Event &e);
	void logic();
	void render();
};


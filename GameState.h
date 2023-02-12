#pragma once
#include "Singletons.h"

struct GameState
{
	virtual void logic() = 0;
	virtual void render() = 0;
	virtual void handleInput(SDL_Event& e) = 0;

	virtual ~GameState() = 0;
};

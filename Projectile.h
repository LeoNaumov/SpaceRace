#pragma once
#include "Singletons.h"
struct Projectile
{
	SDL_Rect rect;
	int vel;

	Projectile();
	void render(SDL_Renderer *r);
};


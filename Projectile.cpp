#include "Projectile.h"

Projectile::Projectile()
{
	rect.w = 15;
	rect.h = 15;
	rect.y = rand() % 600;
	int temp = rand() % 2;
	if (temp == 1) { 
		rect.x = -10; 
		vel = 3;
	}
	else{ 
		rect.x = 810;
		vel = -3;
	}
}

void Projectile::render(SDL_Renderer* r)
{
	rect.x += vel;
	SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(r, &rect);
}
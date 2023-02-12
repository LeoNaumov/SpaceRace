#include "Player1.h"


Player1::Player1(SDL_Renderer* r):
	text(r)
{
	text.loadFromFile("spaceship.png");
	posX = 200;
	posY = 800;
	vel = 0;
	rect.x = posX;
	rect.y = posY;
	rect.w = 48;
	rect.h = 65;
}

void Player1::handleInput(SDL_Event &e)
{
	if (player == 0) {
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w: vel = -10; break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_w: vel = 0; break;
			}
		}
		
	}
	else {
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: vel = -10; break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: vel = 0; break;
			}
		}
	}

}

void Player1::logic() 
{
	if (player == 1) {
		posX = 500;
	}
	posY += vel;
	rect.x = posX;
	rect.y = posY;
}

void Player1::render()
{
	text.render(posX,posY);
}
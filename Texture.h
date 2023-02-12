#pragma once
#include "Singletons.h"


struct LTexture
{

	SDL_Renderer* gRenderer;

	LTexture(SDL_Renderer*);

	~LTexture();

	bool loadFromFile(std::string path);

	void free();

	void render(int x, int y, SDL_Rect* clip = NULL);

	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};


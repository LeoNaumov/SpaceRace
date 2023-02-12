#include "Texture.h"

LTexture::LTexture(SDL_Renderer* r)
{
	gRenderer = r;
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

bool LTexture::loadFromFile(std::string path)
{
	free();


	mTexture = IMG_LoadTexture(gRenderer, path.c_str());
	if (mTexture == NULL)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
	}


	return mTexture != NULL;
}
void LTexture::render(int x, int y, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

LTexture::~LTexture()
{
	free();
}

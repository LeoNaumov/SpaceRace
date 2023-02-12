#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Projectile.h"
#include "Timer.h"
#include "Player1.h"

struct TestScene : public GameState
{
	void logic();
	void render();
	void handleInput(SDL_Event& e);

	bool init;
	int score1;
	int score2;

	TestScene(SDL_Renderer** r, GameStateManager& GSM);
	~TestScene();

	SDL_Renderer** renderer;
	GameStateManager& GSM;

	LTimer timer;
	std::vector<Projectile*> ents;
	Player1* p1;
	Player1* p2;
};


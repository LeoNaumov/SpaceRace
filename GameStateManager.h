#pragma once
#include "GameState.h"

struct GameStateManager
{
	GameState* currState;
	void changeState(GameState*);
	GameStateManager(GameState*);
	~GameStateManager();
};


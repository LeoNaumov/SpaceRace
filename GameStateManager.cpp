#include "GameStateManager.h"

GameStateManager::GameStateManager(GameState* gS)
{
	currState = gS;
}

void GameStateManager::changeState(GameState* gS)
{
	if (currState != NULL)
		delete currState;
	currState = gS;
}
GameStateManager::~GameStateManager()
{
	delete currState;
}
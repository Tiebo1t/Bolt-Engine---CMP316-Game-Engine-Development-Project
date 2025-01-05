#include "GameState.h"

void Bolt::GameState::setCurrentState(State s)
{
	// Sets the current gamestate to what is passed in
	currentState = s;
}

Bolt::State Bolt::GameState::getCurrentState()
{
	// Returns the current game state
	return currentState;
}

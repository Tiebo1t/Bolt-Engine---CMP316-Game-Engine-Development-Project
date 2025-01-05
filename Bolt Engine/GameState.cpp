#include "GameState.h"

void Bolt::GameState::setCurrentState(State s)
{
	currentState = s;
}

Bolt::State Bolt::GameState::getCurrentState()
{
	return currentState;
}

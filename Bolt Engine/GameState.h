// Game State Class
// Simple game state controller. enum lists possible game states (can be modified), tracks and updates the current state
// @author Paul Robertson

#pragma once

namespace Bolt
{
	enum class State { Level1, Level2 };

	class GameState
	{
	public:
		// Set the current state
		void setCurrentState(State s);
		// Returns the current state.
		State getCurrentState();

	protected:
		State currentState;
	};
}




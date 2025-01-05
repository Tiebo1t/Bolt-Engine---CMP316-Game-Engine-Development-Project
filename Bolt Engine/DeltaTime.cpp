#include "DeltaTime.h"

Bolt::DeltaTime::DeltaTime()
{
}

Bolt::DeltaTime::~DeltaTime()
{
}

// http://www.mcihanozer.com/tips/c/calculating-delta-time/ accessed: 21/12/24
void Bolt::DeltaTime::update()
{
	// Gets time from frame to frame 
	auto now = std::chrono::steady_clock::now(); // Gets the current time
	dt = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f; // Removes the last update from the current time and converts to seconds
	lastUpdate = now; // Records the end time for each frame
}

double Bolt::DeltaTime::getDeltaTime()
{
	return dt; // Returns delta time value
}

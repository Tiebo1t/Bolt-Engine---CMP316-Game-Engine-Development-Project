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
	auto now = std::chrono::steady_clock::now();
	dt = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
	lastUpdate = now;
}

double Bolt::DeltaTime::getDeltaTime()
{
	return dt;
}

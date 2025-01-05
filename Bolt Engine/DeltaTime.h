#pragma once
#include <chrono>

namespace Bolt
{

	class DeltaTime
	{
	public:
		DeltaTime();
		~DeltaTime();

		// Update constantly ran throughout game loop
		void update();
		double getDeltaTime();

	private:
		// variables for storing delta time and time since previous update
		double dt;
		std::chrono::steady_clock::time_point lastUpdate;
	};

}


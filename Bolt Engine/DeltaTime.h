#pragma once
#include <chrono>

namespace Bolt
{

	class DeltaTime
	{
	public:
		DeltaTime();
		~DeltaTime();

		void update();
		double getDeltaTime();

	private:
		double dt;
		std::chrono::steady_clock::time_point lastUpdate;
	};

}


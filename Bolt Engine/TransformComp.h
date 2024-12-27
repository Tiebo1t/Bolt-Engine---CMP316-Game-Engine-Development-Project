#pragma once
#include "Components.h"

namespace Bolt
{

	class TransformComp : public Components // Pass in parameters to initialise and SDL rectangle as an object 
	{
		TransformComp();
		~TransformComp();
		void Start();
		void Update();
		void Render();

	};

}

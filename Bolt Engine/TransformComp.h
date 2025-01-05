#pragma once
#include "Components.h"

namespace Bolt
{

	class TransformComp : public Components // NOT USED IN SUBMITTED ENGINE
	{
		TransformComp(GameObject* owner);
		~TransformComp();
		void Start();
		void Update();
		void Render();

	};

}

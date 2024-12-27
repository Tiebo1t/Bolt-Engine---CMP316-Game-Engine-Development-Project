#pragma once

namespace Bolt
{

	class GameObject;
	class Components
	{
	public:
		Components();
		virtual ~Components();
		virtual void Start();
		virtual void Update();
		virtual void Render();

	};


}



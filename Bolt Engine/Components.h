#pragma once

namespace Bolt
{

	class GameObject;
	class Components
	{
	public:
		Components(GameObject* owner);
		virtual ~Components();
		virtual void Start();
		virtual void Update();
		virtual void Render();

	private:
		GameObject* gameObject;
	};


}



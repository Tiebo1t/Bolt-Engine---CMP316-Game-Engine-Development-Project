#pragma once
#include "Components.h"
#include <vector>

// https://stackoverflow.com/questions/26851958/component-based-architecture-c - look at

namespace Bolt
{

	class GameObject
	{

		//std::vector<Components*> comps;

		//template <class T>
		//const T* AddComponent()
		//{

		//	T* component = new T();
		//	comps.push_back(T);
		//	return();

		//}

		//template <class T>
		//T* const GetComponent()
		//{

		//	const type_info& tInfo = typeid(T);
		//	for (auto& c : comps)
		//	{

		//		const type_info& cInfo = typeid(*c);
		//		if (cInfo == tInfo)
		//		{

		//			return static_cast<T*>(c.get());

		//		}
		//		return nullptr;
		//	}

		//}


	};

}




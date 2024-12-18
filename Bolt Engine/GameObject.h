#pragma once
#include "Components.h"
#include "StackAllocator.h"
#include <vector>
#include <memory>

// https://stackoverflow.com/questions/26851958/component-based-architecture-c - look at

namespace Bolt
{

	class GameObject : public Components
	{


	private:
		std::vector<Components*> comps;

	public:
		GameObject();
		~GameObject();

		StackAllocator* stackAlloc = new StackAllocator(256);

		template <class T>
		const T* AddComponent()
		{

			T* rp = new(stackAlloc->Alloc(sizeof(T))) T(this);
			stackAlloc->DeAlloc(sizeof(T));

			std::unique_ptr<T> component;
			component.reset(rp);

			comps.push_back(std::move(component));
			return(rp);

		}

		template <class T>
		T* AddComponent(T*&& cPointer)
		{

			std::unique_ptr<T> component(std::move(cPointer));
			T* rp = component.get();
			comps.push_back(std::move(component));
			return(rp);

		}

		template <class T>
		T* const GetComponent()
		{

			const type_info& tInfo = typeid(T);
			for (auto& c : comps)
			{

				const type_info& cInfo = typeid(*c);
				if (cInfo == tInfo)
				{

					return static_cast<T*>(c.get());

				}
				return nullptr;
			}

		}

	};

}




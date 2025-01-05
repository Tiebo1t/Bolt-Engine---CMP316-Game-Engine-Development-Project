#pragma once
#include "Components.h"
#include "StackAllocator.h"
#include <vector>
#include <memory>

// https://stackoverflow.com/questions/26851958/component-based-architecture-c - look at

namespace Bolt
{
	//class Components;
	class GameObject 
	{

	public:
		GameObject();
		~GameObject();

		StackAllocator* stackAlloc = new StackAllocator(5000);

		template <class T>
		T* AddComponent() // const
		{

			T* rp = new(stackAlloc->Alloc(sizeof(T))) T(this);

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

		void Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy, std::string img);
		void Update();
		void Render();

	private:
		std::vector<std::unique_ptr<Components>> comps;

	};

}




#pragma once
#include "Components.h"
#include "StackAllocator.h"
#include <vector>
#include <memory>

namespace Bolt
{

	class GameObject 
	{

	public:
		GameObject();
		~GameObject();

		StackAllocator* stackAlloc = new StackAllocator(5000); // Creates instance of stack allocator with set size of 5000 bytes

		template <class T>
		T* AddComponent()
		{

			T* rp = new(stackAlloc->Alloc(sizeof(T))) T(this); // Allocates the size of T to the stack

			std::unique_ptr<T> component; // Creates a unique pointer for the component
			component.reset(rp);

			comps.push_back(std::move(component)); // Adds the component to the vector array storing all components
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

			const type_info& tInfo = typeid(T); // Represents the component being searched for
			for (auto& c : comps) // Searches all components from the array
			{

				const type_info& cInfo = typeid(*c);
				if (cInfo == tInfo)
				{

					return static_cast<T*>(c.get()); // Returns the component required stored at tInfo

				}
				return nullptr;
			}

		}

		void Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy, std::string img);
		void Update();
		void Render();

	private:
		// Array of unique pointers to all components
		std::vector<std::unique_ptr<Components>> comps;

	};

}




#pragma once

namespace Bolt
{

	class StackAllocator
	{
	public:
		// Stack initially created with a set amount of allocated bytes
		StackAllocator(size_t size);
		~StackAllocator();

		// Functions for adding, removing and clearing the stack
		void* Alloc(size_t size);
		void* DeAlloc(size_t size);
		void* Clear();
		
	private:
		// Variables for traversing the stack
		void* base;
		void* head;
		void* temp;
	};

}



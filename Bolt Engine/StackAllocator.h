#pragma once

namespace Bolt
{

	class StackAllocator
	{
	public:
		StackAllocator(size_t size);
		~StackAllocator();

		void* Alloc(size_t size);
		void* DeAlloc(size_t size);
		void* Clear();
		
	private:

		void* base;
		void* head;
		void* temp;
	};

}



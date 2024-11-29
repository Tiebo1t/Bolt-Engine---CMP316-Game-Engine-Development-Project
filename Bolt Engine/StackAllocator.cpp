#include "StackAllocator.h"
#include <stdlib.h>

Bolt::StackAllocator::StackAllocator(size_t size)
{

	head = base = malloc(size);

}

Bolt::StackAllocator::~StackAllocator()
{

	free(base);

}

void* Bolt::StackAllocator::Alloc(size_t size)
{

	temp = head;
	char* _head = (char*)head;
	_head += size;
	head = (void*)_head;

	return head;
}

void* Bolt::StackAllocator::DeAlloc(size_t size)
{

	temp = head;
	char* _head = (char*)head;
	_head -= size;
	head = (void*)_head;

	return head;
}

void* Bolt::StackAllocator::Clear()
{

	head = base;

	return head;
}

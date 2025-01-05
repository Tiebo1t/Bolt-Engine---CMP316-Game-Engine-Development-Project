#include "StackAllocator.h"
#include <stdlib.h>

Bolt::StackAllocator::StackAllocator(size_t size)
{

	head = base = malloc(size); // Initially sets the head and the base equal to the start of the stack 

}

Bolt::StackAllocator::~StackAllocator()
{

	free(base); // Frees all memory from the stack

}

void* Bolt::StackAllocator::Alloc(size_t size)
{

	// Moves the head up in the stack by size
	temp = head;
	char* _head = (char*)head;
	_head += size;
	head = (void*)_head;

	return head;
}

void* Bolt::StackAllocator::DeAlloc(size_t size)
{

	// Moves the head back down the stack by size, any new data added will overwrite previous data where the head once was
	temp = head;
	char* _head = (char*)head;
	_head -= size;
	head = (void*)_head;

	return head;
}

void* Bolt::StackAllocator::Clear()
{
	// Sets the head back to where the base is effectively "clearing" all data as it still remains, but will be overwritten by any new data on the stack
	head = base;

	return head;
}

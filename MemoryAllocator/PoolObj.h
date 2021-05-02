#pragma once
class PoolObj
{
	int numberOfBlocks;
	int sizeofEachBlock;
	int numFreeBlocks;
	int numInitialized;
	char* memStart;
	char* next;
public:
	
	char* addrFromIndex(char i);

	int indexFromAddr(char* p);

	PoolObj();

	void DestroyPool();

	void* Allocate();

	void deAllocate(void* p);

	~PoolObj();

	void createPool(size_t sizeOfEachBlock, int numOfBlocks);

};

/*
I was tasked with "creating a memory pool allocator which operates over a memory pool".

Fragmentation isn't an issue, but the memory pool should be expandable if necessary.

To do this, I assume I first need to create a memory pool. If I am not allowed to use the library malloc, how should I do this?

I am unsure where to start. Could someone point me to a good resource?

*/
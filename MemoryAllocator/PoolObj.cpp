#include "PoolObj.h"
char* PoolObj::addrFromIndex(char i)
{
	return memStart + (i * sizeofEachBlock);
}
int PoolObj::indexFromAddr(char* p)
{
	return((int)(p - memStart)) / sizeofEachBlock;
}
PoolObj::PoolObj()
{
	numberOfBlocks = 0;
	sizeofEachBlock = 0;
	numFreeBlocks = 0;
	numInitialized = 0;
	memStart = nullptr;
	next = 0;
}
void PoolObj::DestroyPool()
{
	delete[] memStart;
	memStart = nullptr;
}
void* PoolObj::Allocate()
{
	if (numInitialized < numberOfBlocks)
	{
		char* p = (char*)addrFromIndex(numInitialized);
		*p = numInitialized + 1;
		numInitialized++;
	}
	void* ret = nullptr;
	if (numFreeBlocks > 0)
	{
		ret = (void*)next;
		--numFreeBlocks;
		next = addrFromIndex(*(char*)next);
		if (numFreeBlocks != 0)
		{
			next = addrFromIndex(*((char*)next));
			return ret;
		}
		next = nullptr;

	}
	return ret;
}
void PoolObj::deAllocate(void* p)
{
	if (next != nullptr)
	{
		*(int*)p = indexFromAddr(next);
		next = (char*)p;
	}
	else
	{
		*(int*)p = indexFromAddr(next);
		next = (char*)p;
	}
	++numFreeBlocks;
}
PoolObj::~PoolObj()
{
	//DestroyPool();
}
void PoolObj::createPool(size_t sizeOfEachBlock, int numOfBlocks)
{
	this->numberOfBlocks = numOfBlocks;
	this->sizeofEachBlock = sizeOfEachBlock;

}
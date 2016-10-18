#include <stdint.h>

#define N 30

class LBuffer{
private:
	uint32_t neighbor[N];
	uint32_t edgeProperty[N];
	//LBuffer* nextListNode;
	uint32_t nextListNode;
public:
	LBuffer();
	~LBuffer();
};

class LBufferContainer{
private:
	LBuffer* bufArray;
	uint32_t size;
public:
	LBufferContainer();
	int getNewBuffer();
	int getCurrentNode();
	int increaseBuffer();
	~LBufferContainer();
};
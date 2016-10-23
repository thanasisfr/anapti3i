#include <stdint.h>
#include <stdlib.h>

#define N 30

class LBuffer{
public:
    uint32_t neighbor[N];
    uint32_t edgeProperty[N];
    uint32_t nextToInsertInto;
    uint32_t nextListNode;
};

class LBufferContainer{
private:
    LBuffer* bufArray;
    uint32_t currentlyUsed;
    uint32_t maxSize;
    uint32_t increaseFactor;
public:
    LBufferContainer(uint32_t startingSize, uint32_t increaseFactor);
    int insertEdge(uint32_t buffernodeId, uint32_t connectedNodeId);
    int allocNewNode();
    LBuffer* getListNode(int node);
    int increaseBuffer();
    ~LBufferContainer();
};
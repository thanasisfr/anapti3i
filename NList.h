#include "ListBuffer.h"

struct NListNode{
    uint32_t nodeId;
    int node;
    NListNode* nextNode;
};

class NList{
private:
    LBufferContainer* bufCont;
    NListNode* head;
    NListNode* last;
    uint32_t listSize;
public:
    NList();
    int initHeadNode(uint32_t nodeId);
    int insertNode(uint32_t nodeId);
    NListNode* getNodeById(uint32_t nodeId);
    int insertEdge(uint32_t nodeId, uint32_t connectedNodeId);
    void printContents(char* fileName);
    ~NList();
};
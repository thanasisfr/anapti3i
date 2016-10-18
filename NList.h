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
	NListNode* getListHead(uint32_t nodeId);
	~NList();
};
#ifndef LISTNODE_H
#define LISTNODE_H

#include "BufferComponents.h"


class ListNode{
	
private:
	NeighborStruct neighbor;
	EdgePropertyStruct edgeProperty;
	int next;
	
public:
	ListNode();
	~ListNode();
	
};






#endif
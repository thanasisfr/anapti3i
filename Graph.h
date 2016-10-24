#ifndef GRAPH_H
#define GRAPH_H

#define INITSIZE 5

#include "Buffer.h"
#include "IndexArray.h"

class Graph{
	
private:
	
	IndexArray *indexArray;
	Buffer *buffer;
	
public:
	Graph(uint32_t initSize = INITSIZE);
	~Graph();
};



#endif
#include "Graph.h"


Graph::Graph(uint32_t initSize){
	
	this->indexArray = new IndexArray(initSize);
	this->buffer = new Buffer();
}

Graph::~Graph(){
	
	delete (this->indexArray);
	delete (this->buffer);
}
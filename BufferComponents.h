#ifndef BUFFERCOMPONENTS_H
#define BUFFERCOMPONENTS_H

#include <stdint.h>

struct NeighborStruct{
	
public:
	uint32_t neighbor[ARRAY_SIZE];
	uint32_t counter;
	
	NeighborStruct();
	~NeighborStruct();
	
};




struct EdgePropertyStruct{
	
public:
	uint32_t edgeProperty[ARRAY_SIZE];
	uint32_t counter;
	
	EdgePropertyStruct();
	~EdgePropertyStruct();
};

#endif
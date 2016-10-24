#include "Buffer.h"


Buffer::Buffer(){
	
	this->head = NULL;
	this->counter = 0;
}


Buffer::~Buffer(){
	
	free(this->head);
}
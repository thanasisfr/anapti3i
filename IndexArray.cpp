#include "IndexArray.h"
#include <stdint.h>
#include <cstdlib>

IndexArray::IndexArray(int size){
	
	this->currentSize = size;
	this->indexArray = malloc(this->currentSize * sizeof(int));
	for(int i = 0; i < this->currentSize; i++){
		(this->indexArray)[i] = -1;
	}
}


IndexArray::~IndexArray(){
	
	free(this->indexArray);
}


bool IndexArray::duplicate(){
	
	if(this->indexArray = realloc(this->indexArray, 2*(this->currentSize)*sizeof(int)) != NULL){
		for(int i = this->currentSize; i < 2*(this->currentSize); i++){
			(this->indexArray)[i] = -1;
		}
		this->currentSize = 2*(this->currentSize);
		return true;
	}
	return false;
}
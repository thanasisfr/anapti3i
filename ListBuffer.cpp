#include "ListBuffer.h"
#include <assert.h>
#include <string.h>


LBufferContainer::LBufferContainer(uint32_t startingSize, uint32_t increaseFactor){
    this->currentlyUsed = 0;
    this->maxSize = startingSize;
    this->bufArray = (LBuffer*)malloc(sizeof(LBuffer)*(this->maxSize));
    for (uint32_t i = 0; i < this->maxSize; i++){
        memset((this->bufArray[i]).neighbor, 0, N*sizeof(uint32_t));
        memset((this->bufArray[i]).edgeProperty, 0, N*sizeof(uint32_t));
        (this->bufArray[i]).nextListNode = 0;
        (this->bufArray[i]).nextToInsertInto = 0;
    }
    this->increaseFactor = increaseFactor;
}

int LBufferContainer::allocNewNode(){
    (this->currentlyUsed)++;
    assert(this->currentlyUsed <= this->maxSize);
    return (this->currentlyUsed - 1);
}

int LBufferContainer::insertEdge(uint32_t buffernodeId, uint32_t connectedNodeId){
    if (this->currentlyUsed == this->maxSize){
        this->increaseBuffer();
    }
    LBuffer *temp = &this->bufArray[buffernodeId];
    while (temp->nextListNode != 0){           //Go to the last buffer node
        temp = &this->bufArray[temp->nextListNode];
    }
    if (temp->nextToInsertInto != N){            //If current buffer node has space
        temp->neighbor[(temp->nextToInsertInto)] = connectedNodeId;
    } else{                                     //If it doesn't alloc new node
       temp->nextListNode = allocNewNode();
	   temp = &this->bufArray[(temp->nextListNode)];
       temp->neighbor[(temp->nextToInsertInto)] = connectedNodeId;
    }
    (temp->nextToInsertInto)++;
    return 0;
}

LBuffer* LBufferContainer::getListNode(int node){
    return &(bufArray[node]);
}

int LBufferContainer::increaseBuffer(){
    uint32_t prevSize = this->maxSize;
	this->maxSize *= 2;
    LBuffer* prevArray = this->bufArray;
    this->bufArray = (LBuffer*)malloc(sizeof(LBuffer)*this->maxSize);
    memcpy(this->bufArray, prevArray, sizeof(LBuffer)*prevSize);
    free(prevArray);
    for (uint32_t i = this->currentlyUsed; i < this->maxSize; i++){
        LBuffer *temp = &((this->bufArray)[i]);
        memset(temp->neighbor, 0, N*sizeof(uint32_t));
        memset(temp->edgeProperty, 0, N*sizeof(uint32_t));
        temp->nextListNode = 0;
        temp->nextToInsertInto = 0;
    }
	return 0;
}

LBufferContainer::~LBufferContainer(){
    free(this->bufArray);
}
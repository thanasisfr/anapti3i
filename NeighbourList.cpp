#include "NList.h"
#include <stdio.h>


NList::NList(){
	bufCont = new LBufferContainer();
	head = new NListNode();
	head->nextNode = NULL;
	head->nodeId = 0;			//have to init it when reading first node
	head->node = bufCont->getNewBuffer();
	last = head;
	listSize = 1;
}

int NList::initHeadNode(uint32_t nodeId){
	head->nodeId = nodeId;
	return 0;
}

int NList::insertNode(uint32_t nodeId){
	NListNode* newNode;
	newNode = new NListNode();
	if (newNode == NULL) { 
		return -1; 
	}
	last->nextNode = newNode;
	last = newNode;
	newNode->nextNode = NULL;
	newNode->nodeId = nodeId;
	newNode->node = bufCont->getNewBuffer();
	listSize++;
	return 0;
}

NListNode* NList::getListHead(uint32_t nodeId){
	NListNode* temp = head;
	for (int i = 0; i < listSize; i++){
		if (temp->nodeId == nodeId){
			return temp;
		}else{
			temp = temp->nextNode;
		}
	}
	return NULL;
}

NList::~NList(){
	delete bufCont;
	NListNode* temp = head;
	NListNode* temp2;
	for (int i = 0; i < listSize; i++){
		temp2 = temp->nextNode;
		delete temp;
		temp = temp2;
	}
}
#include "NList.h"
#include <stdio.h>

#define STARTSIZETEST 4
#define INCREASEFACTOR 2

NList::NList(){
    bufCont = new LBufferContainer(STARTSIZETEST,INCREASEFACTOR);
	head = new NListNode();
	head->nextNode = NULL;
	head->nodeId = 0;			//have to init it when reading first node
    head->node = bufCont->allocNewNode();
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
    newNode->node = bufCont->allocNewNode();
    listSize++;
    return 0;
}

int NList::insertEdge(uint32_t nodeId, uint32_t connectedNodeId){
    return this->bufCont->insertEdge(nodeId, connectedNodeId);
}

NListNode* NList::getNodeById(uint32_t nodeId){
    NListNode* temp = head;
	for (uint32_t i = 0; i < listSize; i++){
		if (temp->nodeId == nodeId){
			return temp;
		}else{
			temp = temp->nextNode;
		}
	}
	return NULL;
}

void NList::printContents(char* fileName){
    FILE *fp;
    fp = fopen(fileName, "w");
    NListNode *temp = this->head;
    while (temp != NULL){
        fprintf(fp,"Node %d \r\n",temp->nodeId);
        LBuffer *tempBuff= this->bufCont->getListNode(temp->node);
        int printNode = temp->node;
        while (tempBuff->nextListNode != 0){
            fprintf(fp, "Array %d :",printNode);
            for (int i = 0; i < N; i++){
                fprintf(fp, " %d ", tempBuff->neighbor[i]);
            }
            fprintf(fp, "\r\n");
            printNode = tempBuff->nextListNode;
            tempBuff = this->bufCont->getListNode(tempBuff->nextListNode);
        }
        fprintf(fp, "Array %d :", printNode);
        for (int i = 0; i < N; i++){
            fprintf(fp, " %d ", tempBuff->neighbor[i]);
        }
        fprintf(fp, "\r\n");
        fprintf(fp, "\r\n");
        temp = temp->nextNode;
    }
    fclose(fp);
    return;
}

NList::~NList(){
	delete bufCont;
	NListNode* temp = head;
	NListNode* temp2;
	for (uint32_t i = 0; i < listSize; i++){
		temp2 = temp->nextNode;
		delete temp;
		temp = temp2;
	}
}
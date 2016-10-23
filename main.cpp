#include <string>
#include <sstream>
#include <fstream>
#include "NList.h"

int basicInsertTest(NList* indexList);

int main(int argc, char** argv){
    NList* indexList = new NList();
    int error = basicInsertTest(indexList);
    if (error != 0){
        printf("Error during Insert Test return is %d\n", error);
        return -1;
    }

	return 0;
}


//TODO insert at one direction as is p.x. 3->1
// and then insert at "eiserxomeni" direction 1<-3



int basicInsertTest(NList* indexList){
    indexList->initHeadNode(0);
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 70; j++){
            NListNode *tempIndexListNode = indexList->getNodeById(i);
            if (tempIndexListNode == NULL){
                indexList->insertNode(i);
                tempIndexListNode = indexList->getNodeById(i);
            }
            indexList->insertEdge(tempIndexListNode->node,j);
        }
    }
    indexList->printContents("JustTesting.txt");
	return 0;
}


void readStartupFile(char* fileName){
	std::ifstream infile(fileName);
	std::string line;
	std::string delimit = "=";
	while (std::getline(infile, line)){
		//TODO if line has just S stop the loop
		std::istringstream iss(line);
		//TODO have the values read be added in the list
	}
	return;
}
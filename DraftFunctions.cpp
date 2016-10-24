#include "DraftFunctions.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

bool readEdge(){
	
	char buff[MAXLINE];
	if(fgets(buff, MAXLINE, stdin) == NULL){
		cout<<"ok"<<endl;
		return false;
	}
	printf("The string is : %s\n", buff);
	if(strncmp(buff, "S", 1) == 0){   /* OR: strcmp(buff, "S\n") */
		cout<<"ok2"<<endl;
		return false;
	}

	char *tmp;
	int from, to;
	cout<<"ok3"<<endl;
	tmp = strtok(buff, " \n");
	from = atoi(tmp);
	cout<<"ok4"<<endl;
	tmp = strtok(NULL, " \n");
	to = atoi(tmp);
	cout<<"ok5"<<endl;
	printf("%d --> %d\n", from, to);
	return true;
	
}

/*
bool decideOnQuery(){
	
	char buff[32];
	char tmp;
	
	while(fgets(buff, 32, stdin) != NULL){
		if(strncmp(buff, "A", 1) == 0){
			tmp = strtok(buff, " ");
			if(tmp != NULL){
				return readEdge(tmp);
			}
			else{
				return false;
			}
		}
		else if(strncp(buff, "Q", 1) == 0){
			tmp = strtok(buff, " ");
			if(tmp != NULL){
				return biBFS(tmp);
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}

*/
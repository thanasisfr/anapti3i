#include <string>
#include <sstream>
#include <fstream>
#include "NList.h"

int main(int argc, char** argv){



	return 0;
}


//TODO insert at one direction as is p.x. 3->1
// and then insert at "eiserxomeni" direction 1<-3




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
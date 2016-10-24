#ifndef INDEXARRAY_H
#define INDEXARRAY_H


class IndexArray{
	
private:
	int *indexArray;
	int  currentSize;
	
public:
	IndexArray(int size);
	~IndexArray();
	
	bool duplicate();
};




#endif
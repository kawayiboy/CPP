#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

unsigned char* barray;
int arraySize;
void BitArray(unsigned int n){
	int size = sizeof(char);

	if(n%(8*size) != 0)
		arraySize = ((n/(8*size))+1);
	else
		arraySize = n/(8*size);

	barray = new unsigned char[arraySize];

	for(int i = 0; i < arraySize; i++)
		barray[i] = 0;

}

void main()
{
	BitArray(52);
}
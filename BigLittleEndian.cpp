#include <iostream>
#include <stdio.h>

using namespace std;

#define BIG_ENDIAN 0 
#define LITTLE_ENDIAN 1
int TestByteOrder() { 
    short int word = 0x0001; 
    char *byte = (char *) &word; 
    return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN); 
}

unsigned int change_endian(unsigned int x)
{
	unsigned char *ptr = (unsigned char *)&x;
	return (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
}

void main()
{
	unsigned int x = 0x90AB12CD;//0x12345678;

	//cout<<TestByteOrder();

	unsigned int newx = change_endian(x);

	printf ("%x\n", x);
	printf ("%x\n", newx);
	getchar();
}
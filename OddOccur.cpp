//http://www.mitbbs.com/bbsann2/life.faq/JobHunting/mianshiexp/15/M.1284394112_2.S0/Amazon+%B5%E7%C3%E6%BE%AD%C0%FA
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void main()
{
	int theArray[] = {1,2,3,10,11, 3, 4, 4, 10, 1,10,  10, 3,2, 11};

	int len = sizeof(theArray)/sizeof(int);
	int temp = 0;
	for (int i = 0;i<len;i++)
	{
		temp = temp^theArray[i];
	}
	cout<<temp<<endl;
	getchar();
}

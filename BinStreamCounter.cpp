//http://www.mitbbs.com/article_t/JobHunting/32147591.html
//µÚ5

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

struct StreamCounter
{
	StreamCounter()
	{}

	StreamCounter(int c,int v)
	{
		counter = c;
		value = v;
	}

	int counter;
	int value;
};

vector<StreamCounter> sc;

void main()
{
	int bitarray[] = {0,0,0,0,0,1,1,1,1,0,1,0,1};
	int len = sizeof(bitarray)/sizeof(int);

	bool isone = false;

	//if(bitarray[0]==0)
	isone = bitarray[0];//(bitarray[0]==1)?1:0;
	//sc.resize(100);
	sc.push_back(StreamCounter(1,bitarray[0]));
	int index = 0;
	for (int i = 1;i<len;i++)
	{
		if (isone)
		{
			if(bitarray[i]==0)
			{
				sc.push_back(StreamCounter(1,bitarray[i]));
				index++;
				isone=bitarray[i];
			}
			else
			{
				sc[index].counter++;
			}
		}
		else
		{
			if(bitarray[i]==0)
			{
				sc[index].counter++;
			}
			else
			{
				sc.push_back(StreamCounter(1,bitarray[i]));
				index++;
				isone=bitarray[i];
			}
		}
	}

	for(int i = 0;i<sc.size();i++)
	{
		cout<<"("<<sc[i].counter<<","<<sc[i].value<<")";
	}

	getchar();
}
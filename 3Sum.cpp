#include <iostream>
#include <stdio.h>
#include <vector>


//#include <pair.h>
using namespace std;

void main()
{
	map<int,pair<int,int>> IntMap;

	int A[] = {0,-2,5,-10,-7,-3,2,4,8,10};
	int len = sizeof(A)/sizeof(int);
	for (int i = 0;i<len-1;i++)
	{
		for (int j = i+1;j<len;j++)
		{	
			//pair p = make_pair(i,j);
			IntMap.insert(pair<int,pair<int,int>>(A[i]+A[j],make_pair(i,j)));
		}
	}

	for (int i = 0;i<len;i++)
	{
		int temp = -A[i];
		map<int,pair<int,int>>::iterator itr = IntMap.begin();
		itr = IntMap.find(temp);
		if (itr!=IntMap.end())
		{
			cout<<A[IntMap[temp].first]<<" "<<A[IntMap[temp].second]<<" "<<A[i]<<endl;
		}
	}
	getchar();
}
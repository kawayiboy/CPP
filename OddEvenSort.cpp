#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void main()
{
	int arr[] = {3,5,8,2,1,4,7,6};
	int len = sizeof(arr)/sizeof(int);

	vector<int> odds,evens;
	for (int i = 0;i<len;i++)
	{
		if(arr[i]%2 == 0)
			evens.push_back(arr[i]);
		else
			odds.push_back(arr[i]);
	}

	for(int i =1;i<evens.size();i++)
		for (int j = 0;j<evens.size()-i;j++)
		{
			if (evens[j]>evens[j+1])
			{
				int temp = evens[j];
				evens[j] = evens[j+1];
				evens[j+1] = temp;
			}
		}

	for(int i =1;i<odds.size();i++)
		for (int j = 0;j<odds.size()-i;j++)
		{
			if (odds[j]<odds[j+1])
			{
				int temp = odds[j];
				odds[j] = odds[j+1];
				odds[j+1] = temp;
			}
		}

	for (int i = 0;i<len;i++)
	{
		if(i<odds.size())
			arr[i] = odds[i];
		else
			arr[i] = evens[i-odds.size()];
		cout<<arr[i]<<" ";
	}

	getchar();
}
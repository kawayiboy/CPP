#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int minimum = 65535;

int findnearest(int A[], int used[], int idx, int N)
{
	int index = 0;
	for (int i = 0;i<N;i++)
	{
		if(i == idx)
			continue;
		if(used[i] == 1)
			continue;
		
		int diff = abs(A[i]-A[idx]);
		if (diff<minimum)
		{
			minimum = diff;
			index = i;
		}
	}
	return index;
}

int parsum(vector<int> par)
{ 
	int sum = 0;
	for (vector<int>::iterator it= par.begin();it!=par.end();it++)
	{
		sum+=*it;
	}
	return sum;
}

void partition(int A[], int used[],int N,vector<int>& parl, vector<int>& parr)
{
	for (int i = 0;i<N;i++)
	{
		if(used[i] ==1)
			continue;

		used[i] = 1;
		minimum = 65535;
		int index = findnearest(A,used,i,N);
		used[index] = 1;

		if(parsum(parl)>=parsum(parr))
		{
			int minv = min(A[i],A[index]);
			parl.push_back(minv);
			int maxv = max(A[i],A[index]);
			parr.push_back(maxv);
		}
		else
		{
			int minv = min(A[i],A[index]);
			int maxv = max(A[i],A[index]);
			parl.push_back(maxv);
			parr.push_back(minv);
		}
	}
}

int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(A)/sizeof(int);
	vector<int> parl;
	vector<int> parr;
	int* used = new int(len);
	//parl.push_back(0);
	//parl.clear();
	//parr.push_back(0);
	//parr.clear();
	//used = {0};
	parl.resize(len/2);
	//parl.clear();
	parr.resize(len/2);
	//parl.clear();
	memset(used,0,len);
	partition(A,used,len,parl,parr);
	for (vector<int>::iterator it= parl.begin();it!=parl.end();it++)
	{
		if(*it==0)
			continue;
		cout<<*it<<" ";
	}
	cout<<endl;
	for (vector<int>::iterator it= parr.begin();it!=parr.end();it++)
	{
		if(*it==0)
			continue;
		cout<<*it<<" ";
	}
	getchar();
}
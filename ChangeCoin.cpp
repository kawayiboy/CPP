#include <iostream>
#include <stdio.h>
using namespace std;

int coins[4] = {10,8,5,2};

int Change(int sum, int coin[],int numcoins)
{
	int min = sum;
	for (int i = 0;i<numcoins;i++)
	{
		if (sum>coin[i]&&(min>1+Change(sum-coin[i],coin,numcoins)))//迭代动态规划
		{
			min = 1+Change(sum-coin[i],coin,numcoins);
		}
		else if (sum == coin[i])
		{
			min = 1;//return 1;
		}
	}
	return min;
}

int main()
{
	int num = Change(24,coins,4);
	cout<<num;
	getchar();
	return 1;
}

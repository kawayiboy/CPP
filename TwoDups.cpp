#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int arr[] = {3,5,7,3,1,2,6,4,5};
	int len = sizeof(arr)/sizeof(int);
	int dup[2];
	int dupnum = 0;
	vector<int> arrvec;
	arrvec.resize(len);
	//for (int i = 0;i<len-1;i++)
	//{
	//	arrvec.push_back(arr[i]);
	//}

	for (int i = 0;i<len;i++)
	{
		//int min = arr[i];
		int minindex = i;
		for (int j = i+1;j<len;j++)
		{
			if(arr[minindex]>arr[j])
				minindex = j;
			if(arr[i] == arr[j]&&arr[j]!=dup[dupnum])
			{
				dup[dupnum] = arr[i];
				dupnum++;

				if(dupnum==2)
					break;
			}
		}
		if(dupnum==2)
			break;

		swap(arr[minindex],arr[i]);
	}

	//vector<int>::iterator itr = arrvec.begin();

	//for (int i = 0;i<len;i++)
	//{
	//	itr=find(arrvec.begin(),arrvec.end(),arr[i]);
	//	if(itr != arrvec.end()){
	//		cout<<arr[i]<<endl;
	//	}
	//	arrvec.push_back(arr[i]);
	//}


	cout<<dup[0]<<dup[1]<<endl;
	getchar();
	return 1;
}
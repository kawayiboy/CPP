//http://www.careercup.com/question?id=14539804
#include <iostream>

using namespace std;

void printNGE(int arr[], int n)
{
	int next = -1;
	int i = 0;
	int j = 0;
	for (i=0; i<n; i++)
	{
		next = -1;
		for (j = i+1; j<n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
		printf("%d ¨C> %d\n", arr[i], next);
		if(next!=-1)
			arr[i] = next;
	}
}

void function(int array[], int len)
{
	int currentNum = array[len - 2];
	int greatestSoFar = array[len-1];


	for(int i = len - 2 ; i >=0 ; --i)
	{
		currentNum = array[i];
		array[i] = greatestSoFar;
		(greatestSoFar > currentNum) ? greatestSoFar = greatestSoFar : greatestSoFar = currentNum;
	}
}

void main()
{
	int arr[] = {4, 12, 43, 3, 2, 9, 4, 12, 2, 8, 0} ;

	int len = sizeof(arr)/sizeof(int);
	int max = arr[len-1];
	//for (int i = len-2;i>=0;i--)
	//{
	//	if (arr[i]<max)
	//	{
	//		arr[i] = max;
	//	}
	//	else
	//	{
	//		int temp = max;
	//		max = arr[i];
	//		arr[i] = temp;
	//	}
	//}

	//for(int i = len-2; i>= 0;i--) 
	//	if(arr[i+1]>arr[i]) {
	//		arr[i]= arr[i+1];
	//	}

	printNGE(arr,len);

	for (int i = 0;i<len;i++)
		cout<<arr[i]<<" ";

	getchar();
}
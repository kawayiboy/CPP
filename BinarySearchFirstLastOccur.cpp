//http://cs-technotes.blogspot.com/2010/12/binary-search-find-integer-its-first.html
#include <iostream>

using namespace std;

/*
modify the previous general binary search, to make sure x[l]<target and x[r]>=target and l<r 
thus r points to the first occurrence of the target integer
*/ 
int binarySearchFirstOccur(int* arr, int x,int len)
{
	int l=0,r=len-1;
	int mid=(l+r)/2;

	while(l+1!=r){ //l+1==r => x[l]<x and x[r]>=x and l<r
		if(arr[mid]<x)
			l=mid;    
		else
			r=mid;
		mid=(l+r)/2;
	}
	if(r>len||arr[r]!=x)
		return -1;//didnt find the integer
	else
		return r;//r is the first occurrence index 
}

/*
modify the general binary search, to make sure x[l]<=target and x[r]>target and l<r 
thus l points to the last occurrence of the target integer
*/
int binarySearchLastOccur(int* arr, int x,int len)
{
	int l=0,r=len-1;
	int mid=(l+r)/2;

	while(l+1!=r){ //l+1==r => x[l]<=x and x[r]>x and l<r
		if(arr[mid]>x) //x is in the left
			r=mid;    
		else
			l=mid; 
		mid=(l+r)/2;
	}
	if(r>len||arr[l]!=x)
		return -1;//didnt find the integer
	else
		return l;//l is the last occurrence index 
}

void main()
{
	int arr[] = {1,2,3,3,3,5,6,7};
	int len = sizeof(arr)/sizeof(int);

	int firstoccur = binarySearchFirstOccur(arr,3,len);
	int lastoccur = binarySearchLastOccur(arr,3,len);

	cout<<"First Occur:"<<firstoccur<<"Last Occur:"<<lastoccur;
	getchar();
}
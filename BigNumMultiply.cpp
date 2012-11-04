#include <iostream>
using namespace std;

void toAscii(char A[],int len)
{
	for (int i = 0;i<len;i++)
	{
		A[i]+='0';
	}
}

void fromAscii(char A[],int len)
{
	for (int i = 0;i<len;i++)
	{
		A[i]-='0';
	}
}

void Multiply(char A[],char B[] )
{
	int n = strlen(A);
	int m = strlen(B);

	char* result = new char(n+m+1);
	memset(result,0,sizeof(char)*(n+m+1));

	for (int i = 0;i<n;i++)
	{
		cout<<A[i];
	}
	cout<<endl<<"*"<<endl;

	for (int i = 0;i<m;i++)
	{
		cout<<B[i];
	}
	cout<<endl;

	fromAscii(A,n);
	fromAscii(B,m);
	for (int i = n-1;i>=0;i--)
		for (int j = m-1;j>=0;j--)
		{
			result[i+j+1]+=A[i]*B[j];
			result[i+j]+=result[i+j+1]/10;
			result[i+j+1]=result[i+j+1]%10;
		}

	toAscii(result,n+m+1);
	result[n+m] = '\0';

	for (int i = 0;i<n+m+1;i++)
	{
		cout<<result[i];
	}
	
}

void main()
{
	char A[] = "9999";
	char B[] = "999999999";
	
	Multiply(A,B);

	getchar();
}
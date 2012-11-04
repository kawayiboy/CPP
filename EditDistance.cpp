//http://www.cs.middlebury.edu/~dkauchak/classes/cs302/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int minimum(int x,int y,int z)
{
	int min = x; /* assume x is the largest */

	if (y < min) { /* if y is larger than max, assign y to max */
		min = y;
	} /* end if */

	if (z < min) { /* if z is larger than max, assign z to max */
		min = z;
	} /* end if */

	return min; /* max is the largest value */
}

int main()
{
	string strA = "ABCBDAB";//"simple";
	string strB = "BDCABA";//"apple";
	int m = strA.length();
	int n = strB.length();

	vector<vector<int> > dis(m+1, vector<int>(n+1)); 

	for (int i = 0;i<=m;i++)
	{
		dis[i][0] = i;
	}

	for(int j = 0;j<=n;j++)
	{
		dis[0][j] = j;
	}

	for (int i = 1;i<=m;i++)
		for(int j = 1;j<=n;j++)
		{
			if(strA[i-1]==strB[j-1])
				dis[i][j] = dis[i-1][j-1];
			else
				dis[i][j] = minimum(dis[i-1][j],dis[i][j-1],dis[i-1][j-1])+1;//min((min(dis[i-1][j],dis[i][j-1])),dis[i-1][j-1])+1;
		}

	cout<<"The distance of two string is "<<dis[m][n];

	return 1;
}
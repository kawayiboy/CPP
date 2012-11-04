#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

vector<pair<char,int>> rightnum;

int search(string& txt,string& pat) 
{ 
	int N = txt.length();
	int M = pat.length();
	int skip; 
	for (int i = 0; i <= N-M; i += skip) 
	{ 
		skip = 0; 
		for (int j = M-1; j >= 0; j--)
		{
			if (pat[j] != txt[i+j]) 
			{ 
				skip = max(1, j - rightnum[txt[i+j]-'A'].second); 
				break; 
			}
		} 
		if (skip == 0) return i;
	} 
	return N;
}

int main()
{

	string txt = "INAHAYSTACKNEEDLEINA";
	string pat = "NEEDLE";

	//int R = strA.length();

	int M = pat.length();

	//int right[R]; 
	
	int R=26;
	for (int c = 0; c < R; c++) 
	{
		pair<char,int>tmppair('A'+c,-1);
		rightnum.push_back(tmppair);
		//right[c] = -1; 
	}
	for (int j = 0; j < M; j++) 
		rightnum[pat[j]-'A'].second = j; 

	int pos = search(txt,pat);
	cout<<pos;

	return 1;
}
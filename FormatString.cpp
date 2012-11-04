#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<string> stringarr;
	string str = "tHis    is 1   strinG.";//"tHis is 1   strinG";
	//cout<<str[0];
	int pos = str.find(" ");
	int prepos = 0;

	while (pos!=-1)
	{
		string temp = str.substr(prepos,pos-prepos);
		stringarr.push_back(temp);
		prepos = pos+1;
		pos = str.find_first_of(' ',prepos);
		int nextpos = str.find_first_of(' ',pos+1);
		while(nextpos-pos==1)
		{
			pos = nextpos;
			nextpos = str.find_first_of(' ',pos+1);
		}
		cout<<temp<<endl;
		temp.erase();
	}
	string temp = str.substr(prepos);
	stringarr.push_back(temp);

	for (int i = 0;i<stringarr.size();i++)
	{
		for (int j= 0;j<stringarr[i].size();j++)
		{
			if(j==0)
			{
				if(stringarr[i][j]>'a'&&stringarr[i][j]<'z')
					stringarr[i][j] = stringarr[i][j]-'a'+'A';
			}
			else
			{
				if(stringarr[i][j]>'A'&&stringarr[i][j]<'Z')
					stringarr[i][j] = stringarr[i][j]-'A'+'a';
			}
		}
		cout<<stringarr[i];
	}

	getchar();
    return 1;
}
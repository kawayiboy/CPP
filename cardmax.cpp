/*
Given a variable number of playing cards, form the best hand that does not
exceed 21. The cards are in the set [23456789JQKA], where 2-9 are worth their
face value, J Q and K are worth 10, and A can be selected to be worth either 1
and 11. In this scenario, you are only playing with one suit, so there is never
more than one of each card.

Input:

The first line is a single number, which is the number of lines to follow. Each
line after that is a sequence of characters in the above set.

Output:

For each input line of cards, output the highest possible score that does not
exceed 21.

Example:

STDIN:

4
296J
85
A37
475A

STDOUT:

21
13
21
20
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a,b;
	//char cardstr[20];
	string cardstr;
	scanf("%d",&a);

	for(int i=0;i<a;i++)
	{
		cin>>cardstr;
		//cout<<cardstr;
		char cardchar;
		int totvalue = 0;
		int findnum = 0;
		int findpos = 0;
		for(int k = 0;k <cardstr.length()&&k <cardstr.length()-findnum;k++)
		{
			if(strcmp((cardstr.substr(k,k+1).c_str()),"A")==0)
			{
				char tempchar = (*cardstr.substr(k,k+1).c_str());
				char replacechar = (*cardstr.substr(cardstr.length()-1-findnum,cardstr.length()-findnum).c_str());
				cardstr[k] = replacechar;
				cardstr[cardstr.length()-1-findnum] = tempchar;
				findnum++;
			}
		}
	

		for(int k = 0;k <cardstr.length();k++)
		{
			cardchar = (*cardstr.substr(k,k+1).c_str());
			int number = cardchar - '0';
			if(number>=2&&number<=9)
				totvalue +=number;
			else if(cardchar=='J'||cardchar=='Q'||cardchar=='K')
				totvalue +=10;
			else if(cardchar=='A')
			{
				if(totvalue+11<=21)
					totvalue +=11;
				else
					totvalue +=1;
			}
		}

		if(totvalue>21)
			totvalue = 21;

		printf("%d\n",totvalue);
	}

	return 1;
}
//http://stackoverflow.com/questions/7894374/string-distance-transpositions-only
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main()
{
	string fromString = "mug";
	string toString = "gum";
	int n = fromString.size();
	int amo = 0;

	for (int i = 0; i < n; i++)
	{
		if (fromString[i] == toString[i])
			continue;

		char toWhat = toString[i];
		int where = -1;
		for (int j = i; j < n; j++)
		{
			if (fromString[j] == toWhat)
			{
				where = j;
				break;
			}
		}
		while (where != i)
		{
			char temp = fromString[where];
			fromString[where] = fromString[where - 1];
			fromString[where - 1] = temp;
			cout<<fromString.c_str()<<endl;
			where--;
			amo++;
		}
	}
	cout << amo << endl;
	getchar();
}
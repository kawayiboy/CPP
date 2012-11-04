//https://github.com/CharleneJiang/InterviewPuzzle/blob/master/FindMostlyBoughtItem.cpp
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void main()
{
	string ItemName = "item1";
	vector<pair<string,int>> Items;
	Items.push_back(make_pair("item1",0));
	Items.push_back(make_pair("item2",0));
	Items.push_back(make_pair("item3",0));
	vector<pair<string, string>> CustItems;
	CustItems.push_back(make_pair("custA","item1"));
	CustItems.push_back(make_pair("custB","item1"));
	CustItems.push_back(make_pair("custA","item2"));
	CustItems.push_back(make_pair("custB","item3"));
	CustItems.push_back(make_pair("custC","item1"));
	CustItems.push_back(make_pair("custC","item3"));
	CustItems.push_back(make_pair("custD","item2"));
	vector<string> Customs;

	for (int i = 0;i<CustItems.size();i++)
	{
		if (CustItems[i].second==ItemName)
		{
			Customs.push_back(CustItems[i].first);
		}
	}

	//vector<pair<string, string>> CustItems2;
	vector<vector<string>> CustItems2(Customs.size());
	for (int i = 0;i<CustItems.size();i++)
	{
		//vector<string>::iterator It = find(Customs.begin(),Customs.end(),CustItems[i].first);
		//if(It!=Customs.end())
		//{
		//	vector<string, vector<string>>::iterator It2 = find(CustItems2.begin(),CustItems2.end(),(*It));
		//	if(It2==CustItems2.end())
		//	{
		//		vector<string> tempitem;
		//		CustItems2.push_back(make_pair((*It),tempitem.push_back(CustItems[i].second)));
		//	}
		//	else
		//	{
		//		vector<string> tempitem = (*It2).second;
		//			tempitem.push_back(CustItems[i].second);
		//	}
		//}


		for(int j = 0;j<Customs.size();j++)
		{
			if(Customs[j] == CustItems[i].first&&CustItems[i].second!=ItemName)
				CustItems2[j].push_back(CustItems[i].second);
		}
	}


	int maxid = 0;
	int max = 0;
	for(int j = 0;j<Items.size();j++)
	{
		for (int i = 0;i<CustItems2.size();i++)
		{
			vector<string> tempitem = CustItems2[i];

			vector<string>::iterator It = find(tempitem.begin(),tempitem.end(),Items[j].first);
			if (It != tempitem.end())
			{
				Items[j].second++;
			}
		}
		if(Items[j].second>max)
		{
			maxid = j;
			max = Items[j].second;
		}
	}

	cout<<Items[maxid].first;
	getchar();
}
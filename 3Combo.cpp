//http://www.mychinamyhome.com/forum/thread-142104-1-1.html
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<pair<char,int> > log;
	log.push_back(make_pair('A',1));
	log.push_back(make_pair('A',2));
	log.push_back(make_pair('A',3));
	log.push_back(make_pair('B',2));
	log.push_back(make_pair('B',3));
	log.push_back(make_pair('C',1));
	log.push_back(make_pair('B',4));
	log.push_back(make_pair('A',4));

	map<char,int> maphit;
	map<int,int> maphitcount;
	for(int i = 0;i<log.size();i++)
	{
		if(maphit.empty())
			maphit.insert(make_pair(log[i].first,log[i].second));
		else
		{
			map<char,int>::iterator It;
			It = maphit.find(log[i].first);
			if(It!= maphit.end())
			{
				if((*It).second>100)
				{
					int temp = (*It).second%100;
					temp*=10;
					temp+=log[i].second;
					(*It).second = temp;

					map<int,int>::iterator It2;
					It2 = maphitcount.find((*It).second);
					if(It2!=maphitcount.end())
						maphitcount[(*It).second]++;
					else
						maphitcount.insert(make_pair((*It).second,1));
				}
				else
				{
					(*It).second*=10;
					(*It).second+=log[i].second;

					if((*It).second>100)
					{
						map<int,int>::iterator It2;
						It2 = maphitcount.find((*It).second);
						if(It2!=maphitcount.end())
							maphitcount[(*It).second]++;
						else
							maphitcount.insert(make_pair((*It).second,1));
					}
				}
			}
			else
			{
				maphit.insert(make_pair(log[i].first,log[i].second));
			}
		}
	}

	int maxindex = 0;
	int max = -1;

	map<int,int>::iterator itr = maphitcount.begin(), maxit = maphitcount.begin();
	for ( itr = maphitcount.begin(); itr != maphitcount.end(); ++itr) {
		if ( itr->second>maxit->second)
		{
			maxit=itr;
		}
	}
	cout<<maxit->first;

	getchar();
}
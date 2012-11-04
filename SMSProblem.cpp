////http://www.careercup.com/question?id=11770891
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void main()
//{
//	vector<vector<char>> sms;
//	sms.resize(9);
//	sms[1].push_back('A');
//	sms[1].push_back('B');
//	sms[1].push_back('C');
//	sms[1].push_back('2');
//
//	sms[2].push_back('D');
//	sms[2].push_back('E');
//	sms[2].push_back('F');
//	sms[2].push_back('3');
//
//	sms[3].push_back('G');
//	sms[3].push_back('H');
//	sms[3].push_back('I');
//	sms[3].push_back('4');
//
//	sms[4].push_back('J');
//	sms[4].push_back('K');
//	sms[4].push_back('L');
//	sms[4].push_back('5');
//
//	sms[5].push_back('M');
//	sms[5].push_back('N');
//	sms[5].push_back('O');
//	sms[5].push_back('6');
//
//	sms[6].push_back('P');
//	sms[6].push_back('Q');
//	sms[6].push_back('R');
//	sms[6].push_back('S');
//	sms[6].push_back('7');
//
//	sms[7].push_back('T');
//	sms[7].push_back('U');
//	sms[7].push_back('V');
//	sms[7].push_back('8');
//
//	sms[8].push_back('W');
//	sms[8].push_back('X');
//	sms[8].push_back('Y');
//	sms[8].push_back('Z');
//	sms[8].push_back('9');
//
//	string input = "2*";
//	string output;
//	output.resize(100);
//
//	int num = 0;
//	int index = 0;
//	int counter = 0 ;
//
//	for (int i = 0;i<input.size();i++)
//	{
//
//		if(input[i]=='1')
//		{
//			if(index!=0)
//				output[counter++] =sms[index-1][num%(sms[index-1].size())];
//			num = 0;
//			index=0;
//			continue;
//		}
//		else if(input[i]=='*')
//		{
//			if(index!=0)
//				output[counter++] =sms[index-1][num%(sms[index-1].size())];
//			output[counter++] = ' ';
//			num = 0;
//			index=0;
//		}
//		else if(input[i]=='#')
//		{
//			if(index!=0)
//				output[counter++] =sms[index-1][num%(sms[index-1].size())];
//			num = 0;
//			index = 0;
//		}
//		else if(input[i]>'1'&&input[i]<='9')
//		{
//			if(i==0)//||input[i]!=input[i-1]
//			{
//				index = input[i]-'0';
//				num = 0;
//			}
//			else
//			{
//				if((input[i]-'0')==index)
//					num++;
//				else
//				{	if(index!=0)		
//					  output[counter++] =sms[index-1][num%(sms[index-1].size())];
//					index = input[i]-'0';
//					num = 0;
//				}
//			}
//		}
//	}
//	if(index!=0)
//		output[counter++] =sms[index-1][num%(sms[index-1].size())];
//
//	output[counter] = '\0';
//	cout<<output.c_str();
//
//	getchar();
//}

//http://www.careercup.com/question?id=4031401
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> sms;
int count=0;
void permutation(string instr,int k,string out)
{
	if(k == instr.size())
	{
		for(int j = 0;j<instr.size();j++)
			cout<<out[j];
		cout<<endl;
		count++;
		return;
	}
	for(int i = 0;i<sms[instr[k]-'0'].size();i++)
	{
		out[k] = sms[instr[k]-'0'][i];
		permutation(instr,k+1,out);
	}
}

void main()
{
	
	sms.push_back("");
	sms.push_back("");
	sms.push_back("ABC");
	sms.push_back("DEF");
	sms.push_back("GHI");
	sms.push_back("JKL");
	sms.push_back("MNO");
	sms.push_back("PQRS");
	sms.push_back("TUV");
	sms.push_back("WXYZ");

	string in = "2342";
	string out = "";
	out.resize(in.size()+1);
	permutation(in,0,out);
	cout<<count<<endl;
	getchar();
}
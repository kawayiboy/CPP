#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int char2int(char* a, int len)
{
    int num = 0;
    for(int i = 0;i<len;i++)
    {
        num*=10;
        num+=a[i]-'0';
    }
    
    return num;
}

void int2char(int num,char* str) 
{
    int tempnum = num;
    int index = 0;
    while (tempnum) {
        index++;
        tempnum/=10;
    }
    
    tempnum = num;
    //char* str = new char[index+1];
    for(int i = index-1;i>=0;i--)
    {
        int digit = tempnum%10;
        tempnum/=10;
        str[i] = digit+'0';
    }
    
    str[index] = '\0';
    return str;
    
}

int main()
{
    string startdate = "09111989";
    string enddate = "10062012";
    
    int dayinm[] = {31,30,29,30,31,30,31,31,30,31,30,31};
    string sd = startdate.substr(0,4);
    string ed = enddate.substr(0,4);
    string sy = startdate.substr(4,4);
    string ey = enddate.substr(4,4);
    int synum = char2int((char*)sy.c_str(), sy.length());
    int eynum = char2int((char*)ey.c_str(), ey.length());
    int count = eynum - synum +1;
    for (int i = 0; i<count; i++) {
        int day = (sy[3]-'0')*10+(sy[2]-'0');
        int month = (sy[1]-'0')*10+(sy[0]-'0');
        
        if(month<=12&&month>0)
        {
            if(day<dayinm[month-1]&&day>0)
                cout<<sy[3]<<sy[2]<<sy[1]<<sy[0]<<sy<<endl;
        }
        
        synum++;
        int2char(synum,(char*)sy.c_str());
    }
    
     
    return 1;
}
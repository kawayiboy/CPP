#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    char substr[] = "abc";
    char fullstr[] = "abcdeffdefegabcabc";
    
    int lensub = strlen(substr);//sizeof(substr)/sizeof(char);
    int lenfullstr = strlen(fullstr);//sizeof(fullstr)/sizeof(char);
    
    for(int i = lenfullstr-lensub;i>=0;i--)
    {
        int j = 0;
        for (; j<3; j++) {
            if(fullstr[i+j]=='\0'||fullstr[i+j]!=substr[j])
                break;
        }
        if(j!=3)
            continue;
        else {
            fullstr[i]='x';
            for (int k = i+1; k<lenfullstr-2; k++) {
                fullstr[k] = fullstr[k+2];
            }
            fullstr[lenfullstr-2]='\0';
        }
    }
    
    int index = 0;
    while(fullstr[index]!='\0')
    {
        printf("%c",fullstr[index++]);
    }
    return 1;
}
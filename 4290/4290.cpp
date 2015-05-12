#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"


int main()
{
    freopen("input.txt", "r", stdin);
    char str[100];
    int CLASS[7] = {};
    while(cin >> str)
    {
        int ip[4]={-1, -1, -1, -1}, ipy[4]={-1, -1, -1, -1};
        sscanf(str, "%d.%d.%d.%d~%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3], &ipy[0], &ipy[1], &ipy[2], &ipy[3]);
        if(ip[0]<0||ip[0]>255||ip[1]<0||ip[1]>255||ip[2]<0||ip[2]>255||ip[3]<0||ip[3]>255||ipy[0]<0||ipy[0]>255||ipy[1]<0||ipy[1]>255||ipy[2]<0||ipy[2]>255||ipy[3]<0||ipy[3]>255)
        {
            ++CLASS[5];
            continue;
        }
        if(ip[0]<=126&&ipy[0]==255&&ipy[1]==0&&ipy[2]==0&&ipy[3]==0)
        {
            ++CLASS[0];
            if(ip[0]==10)
            ++CLASS[6];
            continue;
        }
        if(ip[0]<=191&&ip[0]>=128&&ip[0]>127&&ipy[0]==255&&ipy[1]==255&&ipy[2]==0&&ipy[3]==0)
        {
            ++CLASS[1];
            if(ip[0]==172&&ip[1]>=16&&ip[1]<=31)
            ++CLASS[6];
            continue;
        }
        if(ip[0]<=223&&ip[0]>191&&ipy[0]==255&&ipy[1]==255&&ipy[2]==255&&ipy[3]==0)
        {
            ++CLASS[2];
            if(ip[0]==192&&ip[1]==168)
            ++CLASS[6];
            continue;
        }
        if(ip[0]<=239&&ip[0]>=224&&ipy[0]==255&&ipy[1]==255&&ipy[2]==255&&ipy[3]==255)
        {
            ++CLASS[3];
            continue;
        }
        if(ip[0]>=240&&ipy[0]==255&&ipy[1]==255&&ipy[2]==255&&ipy[3]==255)
        {
            ++CLASS[4];
            continue;
        }
        else
        {
            ++CLASS[5]; 
        }
    }
    for(int i=0; i<7; ++i)
        cout << CLASS[i] <<' ';
    cout<<endl;
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    char str[1000];
    while(cin>>str)
    {
        bool flag[1000]={};
        int len=strlen(str);
        int sum=0;
        for(int i=0;i<len;i++)
            if(!flag[str[i]])
            {
                flag[str[i]]=true;
                sum++;
            }
        cout<<sum<<endl;
    }
    return 0;
}

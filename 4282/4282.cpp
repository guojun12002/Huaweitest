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
    int n;
    while(cin>>n)
    {
        bool person[10000]={};
        int i=0;
        int Count=0;
        int num=n;
        while(n>1)
        {
            if(!person[i])
            {
                if(Count==2)
                {
                    person[i]=true;
                    n--;
                }
                Count=(Count+1)%3;
            }
            i=(i+1)%num;
        }
        for(int j=0;j<num;j++)
            if(!person[j])
            {
                cout<<j+1<<endl;
                break;
            }
    }
    return 0;
}

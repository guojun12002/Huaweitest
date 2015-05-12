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
        int sum=0;
        while(n>0)
        {
            if(n%2==0) sum++;
            n/=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}

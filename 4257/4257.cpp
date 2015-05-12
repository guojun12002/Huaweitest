#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    freopen("input.txt","r",stdin);
    int a,b;
    while(cin>>a>>b)
    {
        if(a<b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}

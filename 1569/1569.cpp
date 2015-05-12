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
    int num[30001];
    num[0] = 0;
    for(int i=1; i<=30000; ++i)
    {
        int m = i;
        if(m%7 == 0) num[i] = num[i-1]+1;
        else
            while(m > 0)
            {
                if(m%10 == 7)
                {
                    num[i] = num[i-1]+1;
                    break;
                }
                else num[i] = num[i-1];
                m /= 10;
            }
    }
    while(cin >> n)
        cout << num[n] <<endl;
    return 0;
}

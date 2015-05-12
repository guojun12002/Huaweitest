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
    int num;
    while(cin>>num)
    {
        int n=num;
        char str[10];
        char* s= str;
        do
        {
            *s=(n%10)+'0';
            n/=10;
            s++;
        }while(n>0);
        *s='\0';
        cout<<strlen(str)<<' '<<str<<endl;
    }
    return 0;
}

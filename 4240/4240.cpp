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
    string str;
    while(cin >> str)
    {
        sort(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}

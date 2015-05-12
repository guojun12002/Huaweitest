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
    cin >> n;
    char str[1000];
    for(int i=0; i<n; i++)
    {
        cin >> str;
        int sum = 0;
        int sq[26] = {};
        for(int j=0; j<strlen(str); ++j)
        {
            tolower(str[j]);
            sq[str[j]-'a']++;
        }
        sort(sq, sq+26);
        for(int j=0; j<26; ++j)
            sum += (j+1)*sq[j];
        cout << sum << endl;
    }
    return 0;
}

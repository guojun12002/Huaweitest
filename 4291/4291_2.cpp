#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int maxn = 1000;
char s[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    char store[8][17] = {0};
    int counts[8] = {0};
    int rows[8] = {0};
    int row,kase = 0;
    while(cin >> s >> row)
    {
        int len = strlen(s);
        int i;
        for(i = 0;i < 16; i++)
        {
            if(s[len - 1 - i] == '\\')
                break;
        }
        i--;
        int equal = 0;
        for(int j = 0;j < kase; j++)
        {
            if(strcmp(store[j],&s[len - 1 -i]) == 0 &&  row == rows[j])
            {
                equal = 1;
                counts[j]++;
                break;
            }
        }

        if(!equal)
        {
            strcpy(store[kase], &s[len - 1 -i]);
            rows[kase] = row;
            counts[kase]++;
            kase ++;
        }
        int j;
        for(j = 0; j < kase; j++)
        {
            cout << store[j] << " " << rows[j] << " " << counts[j] << endl;
        }
    }
    return 0;
}

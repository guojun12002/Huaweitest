#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;


int main()
{
	freopen("input.txt", "r", stdin);
	bool num[100]={};
	for(int i=4; i<100; ++i)
		for(int j=2; j<i; ++j)
			if(i%j == 0)
			{
				num[i] = true;
				break;
			}
	int m;
	while(cin >> m)
	{
		if(m < 4) continue;
		for(int i=4; i<=m; ++i)
			if(num[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}
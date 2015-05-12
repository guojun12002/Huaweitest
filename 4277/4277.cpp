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
	int m;
	while(cin >> m)
	{
		int sum = 0;
		for(int i=0; i<m; i++)
			sum += m*m - m + 1 + i*2;
		if (sum == m*m*m)
		{
			for(int j=0; j<m; j++)
			{
				printf("%d", m*m-m+1+j*2);
				if(j != m-1) printf("+");
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"


int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		cout<<n/2<<endl;
	}
	return 0;
}
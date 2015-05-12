#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;
#define M 1000000000;
const int MAX = 1000001;
int main()
{
	freopen("input.txt", "r", stdin);
	LL num;
	LL* f = new LL[MAX];
	f[0] = 1;
	f[1] = 1;
	for(int i=2; i<MAX; i++)
	{
		f[i] = f[i-1];
		if(i % 2 == 0) f[i] = (f[i] + f[i/2]) % M;
	}
	while(cin >> num)
		cout << f[num] << endl;
	delete f;
	return 0;
}
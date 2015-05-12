#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#include "source/oj.cpp"
typedef long long LL;


int main()
{
	// freopen("input.txt", "r", stdin);
	float num[10];
	int n = 0;
	OutputRotundityArea(num, n);
	for(int i=0; i<n; ++i)
		cout << num[i] << endl;
	return 0;
}
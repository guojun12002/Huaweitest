#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	int aNums[] = {1,-2,3,10,-4,7,2,-5};
	cout<<GetSubArraySum(aNums, 8)<<endl;
	return 0;
}
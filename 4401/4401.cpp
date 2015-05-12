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
	cout<<GetMinPeriod("abcabcabcabc")<<endl;
	cout<<GetMinPeriod("abab")<<endl;
	cout<<GetMinPeriod("aaaa")<<endl;
	return 0;
}
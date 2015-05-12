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
	int result = 0;

    cout<<GetExtFibonacci(-1,1,3)<<endl;
    cout<<GetExtFibonacci(-1,1,6)<<endl;
    cout<<GetExtFibonacci(-1,1,30)<<endl;
    cout<<CalcTotalValueOfExtFibonacci(-1, 1, 2)<<endl;
    cout<<CalcTotalValueOfExtFibonacci(-1, 1, 3)<<endl;
    cout<<CalcTotalValueOfExtFibonacci(-1, 1, 5)<<endl;
	return 0;
}
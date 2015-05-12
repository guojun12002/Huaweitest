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
	char strInput[] = "d545a";
	char strOutput[10] = "";
	ProcessString(strInput,'a','c',strOutput);
	cout<<strOutput<<endl;
	return 0;
}
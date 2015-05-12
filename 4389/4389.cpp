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
	char strInput[] = "ABCDEF";
	char strOutput[10] = "";
	ProcessString(strInput,strOutput);
	cout<<strOutput<<endl;
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
// #include "source/"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	vector<int> e;
	e = v;
	v[0]=2;
	cout<<e[0]<<e[1]<<endl;
	return 0;
}
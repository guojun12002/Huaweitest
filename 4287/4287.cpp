#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
// #include "source/"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	string str;
	while(cin >> str)
	{
		int num = 0;
		vector<int> sq;
		for(int i=0; i<str.length(); ++i)
			if(str[i] == ',')
			{
				sq.push_back(num);
				num = 0;
			}
			else
				num = num * 10 + str[i] - '0';
		sq.push_back(num);
		sort(sq.begin(), sq.end());
		if(!sq.empty())
		{
			cout << sq[0];
			for(int i=1; i<sq.size()-1; ++i)
				if(sq[i] != sq[i-1] + 1 || sq[i] != sq[i+1] - 1)
					cout << ' ' << sq[i];
			cout << ' ' << sq[sq.size()-1] << endl;
		}
	}
	return 0;
}
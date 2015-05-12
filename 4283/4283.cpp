#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
// #include "source/"

int a[10];
stack<int> s;
string str;
set<string> ss;
bool flag[10];
void train(int l, int r, int i)
{
	if(l < 0 || r < l)
		return;
	if(l > 0)
	{
		flag[i] = true;
		train(l-1, r, i+1);
	}
	if(r > l)
	{
		flag[i] = false;
		train(l, r-1, i+1);
	}
	if(l == 0 && r == 0)
	{
		int c = 0;
		for(int j=0; j<i; ++j)
			if(flag[j])
				s.push(a[c++]);
			else
			{
				// cout << s.top() << ' ';
				str.append(1, s.top()+'0');
				str.append(1, ' ');
				s.pop();
			}
		str.erase(str.length()-1);
		ss.insert(str);
		str.clear();
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	while(cin >> N)
	{
		if(N < 1 || N > 9) return 0;
		while(!s.empty())
			s.pop();
		memset(flag, false, 10);
		str.clear();
		ss.clear();
		for(int i=0; i<N; ++i)
			cin >> a[i];
		train(N, N, 0);
		typedef set<string>::iterator sit;
		for(sit i=ss.begin(); i!=ss.end(); ++i)
			cout<<*i<<endl;
	}
	return 0;
}
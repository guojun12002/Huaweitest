#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"

char pre[50], mid[50], ed[50];
char* s;
int n;
int find_pos(char c)
{
	for(int i=0; i<n; ++i)
		if(c == mid[i]) return i;
	return n;
}
void restore(int ml, int mr, int root)
{
	if(ml >= mr || root >= n) return;
	if(ml+1 != mr)
	{
		int m_p = find_pos(pre[root]);
		int m = m_p - ml;
		restore(ml, m_p, root+1);
		restore(m_p+1, mr, root+1+m);
	}
	*s = pre[root];
	++s;
	return;
}
int main()
{
	freopen("input.txt", "r", stdin);
	while(cin >> pre >> mid)
	{
		n = strlen(pre);
		s = ed;
		restore(0, n, 0);
		*s = '\0';
		cout << ed <<endl;
	}
	return 0;
}
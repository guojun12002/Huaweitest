#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int MAX=5000;

int n;
int pre[MAX],mid[MAX],hp[MAX],s[MAX];
int si;
bool flag;

void findchild(int ml, int mr, int root)
{
	if(ml>=mr || root>=n) return;
	if(ml+1 != mr)
	{
		int pm=hp[pre[root]];
		int m=pm-ml;
		if(pm<ml || pm>mr)
		{
			flag=false;
			return;
		}
		findchild(ml, pm, root+1);
		findchild(pm+1, mr, root+1+m);
	}
	if(ml+1==mr && pre[root] != mid[ml])
	{
		flag=false;
		return;
	}
	s[si++]=pre[root];
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	while(scanf("%d",&n) != EOF)
	{
		si=0;
		flag=true;
		//Si=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pre[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&mid[i]);
			hp[mid[i]]=i;
		}
		findchild(0, n, 0);
		if(flag)
		{
			for(int i=0;i<si;i++)
				printf("%d ", s[i]);
			printf("\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
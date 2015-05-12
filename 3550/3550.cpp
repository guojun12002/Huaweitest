#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int N,P;
	while(cin>>N>>P)
	{
		if(N>P || P-N>=100)
		{
			cout<<"null"<<endl;
			continue;
		}
		int M=P-N;
		int a[5]={};
		while(M>0)
		{
			if(M>=50)
			{
				M-=50;
				a[0]++;
				continue;
			}
			if(M>=20)
			{
				M-=20;
				a[1]++;
				continue;
			}
			if(M>=10)
			{
				M-=10;
				a[2]++;
				continue;
			}
			if(M>=5)
			{
				M-=5;
				a[3]++;
				continue;
			}
			if(M>=1)
			{
				M-=1;
				a[4]++;
				continue;
			}
		}
		for(int i=0;i<5;i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}
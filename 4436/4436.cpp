#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		int c;
		int chips[21]={};
		for(int i=0;i<n;i++)
		{
			cin>>c;
			chips[c]++;
		}
		int i;
		for(i=1;i<21;i++)
			if(chips[i]%2==1)
			{
				cout<<i<<endl;
				break;
			}
		if(i>20)
			cout<<-1<<endl;
	}
	return 0;
}
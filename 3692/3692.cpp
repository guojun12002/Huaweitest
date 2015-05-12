#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int beg,end;
	while(cin>>beg>>end)
	{
		if(end>65)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		int t=65-(beg*100)%65;
		if(t<end)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
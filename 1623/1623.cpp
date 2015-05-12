#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		int dx=x2-x1;
		int dy=y2-y1;
		if(dx==0 && dy==0)
		{
			cout<<"CLICK"<<endl;
			continue;
		}
		if(abs(dx)>=abs(dy))
		{
			if(dx<0)
			{
				cout<<"LEFT"<<endl;
				continue;
			}
			else
			{
				cout<<"RIGHT"<<endl;
				continue;
			}
		}
		else
		{
			if(dy<0)
			{
				cout<<"UP"<<endl;
				continue;
			}
			else
			{
				cout<<"DOWN"<<endl;
				continue;
			}
		}
	}
	return 0;
}
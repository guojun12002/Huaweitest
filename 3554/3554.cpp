#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool leap(int year)
{
	if(year%400==0)
		return true;
	else if(year%4==0)
		return true;
	else
		return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	int year,month,day;
	int m1[12]={31,59,90,120,151,181,212,243,273,304,334,365};
	int m2[12]={31,60,91,121,152,182,213,244,274,305,335,366};
	while(cin>>year>>month>>day)
	{
		int days=0;
		for(int i=1990;i<year;i++)
			if(leap(i))
				days+=m2[11];
			else
				days+=m1[11];
		if(month>1)
			if(leap(year))
				days+=m2[month-2];
			else
				days+=m1[month-2];
		days+=day;
		int d=days%5;
		switch(d)
		{
			case 0:cout<<"Sleeping"<<endl;break;
			case 1:
			case 2:
			case 3:cout<<"Fishing"<<endl;break;
			case 4:cout<<"Sleeping"<<endl;break;
		}
	}
	return 0;
}
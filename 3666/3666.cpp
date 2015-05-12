#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string format(string str)
{
	while(true)
	{
		unsigned int pos= str.find(',');
		if(pos!=string::npos)
		{
			str.erase(pos,1);
			continue;
		}
		else
		{
			pos= str.find('.');
			if(pos!=string::npos)
			{
				str.erase(pos,1);
				continue;
			}
			else
				return str;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	string str;
	while(cin>>str)
	{
		unsigned int pos=0;
		unsigned int sum=0;
		unsigned int flag[3]={};
		unsigned int score=0;
		while(pos!=string::npos)
		{
			unsigned int lpos=pos;
			pos=str.find(',',lpos+1);
			string s=format(str.substr(lpos,pos-lpos));
			if(s.length()==4)
			{
				sum++;
				continue;
			}
			else if(s.length()==8)
			{
				flag[1]++;
				continue;
			}
			else if(!(s.substr(0,2).compare("1T")))
			{
				flag[0]++;
				continue;
			}
		}
		if(sum==7) flag[2]++;
		cout<<flag[0]*1+flag[1]*2+flag[2]*2<<endl;
	}
	return 0;
}

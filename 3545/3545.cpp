#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	string str;
	while(cin>>str)
	{
		int length= str.length();
		unsigned long max=str[0]-48;
		int temp= str[0]-48;
		for(int i=0;i<length-1;i++)
		{
			int L=str[i]-48, R=str[i+1]-48;
			if(R>L)
			{
				temp=temp*10+R;
				if(temp>max) max=temp;
			}
			else
			{
				if(temp>max) max=temp;
				temp= str[i+1]-48;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
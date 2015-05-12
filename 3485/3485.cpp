#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int s[10];
	while(cin>>s[0]>>s[1]>>s[2]>>s[3]>>s[4]>>s[5]>>s[6]>>s[7]>>s[8]>>s[9])
	{
		int num[11]={};
		int sum=0;
		for(int i=0;i<10;i++)
			num[s[i]/10]++;
		for(int i=0;i<11;i++)
		{
			sum+=num[i];
			if(i>5)
			{
				cout<<60<<endl;
				break;
			}
			if(sum>4)
			{
				cout<<i*10<<endl;
				break;
			}
		}
	}
	return 0;
}
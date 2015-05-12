#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

unsigned int yueshu(unsigned int n)
{
	unsigned int num=0;
	if(n%2==0)
	{
		for(int i=1;i<=n/2;i++)
			if(n%i==0) num++;
		return num;
	}
	else
	{
		for(int i=1;i<n/2+1;i+=2)
			if(n%i==0) num++;
		return num;
	}
	return num;
}

int main()
{
	freopen("input.txt","r",stdin);
	unsigned int n;
	while(cin>>n)
	{
		bool *light=new bool[n];
		int sum=0;
		for(unsigned int i=2;i<=n;i++)
		{
			unsigned int num=yueshu(i);
			if(num%2==0)
				light[i-1]=true;
			else
				light[i-1]=false;
		}
		for(unsigned int i=0;i<n;i++)
			if(light[i]) sum++;
		cout<<sum<<endl;
		delete []light;
	}
	return 0;
}
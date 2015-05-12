#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		if(n>100)
			cout<<"ERROR"<<endl;
		else if(n>=90)
			cout<<'A'<<endl;
		else if(n>=80)
			cout<<'B'<<endl;
		else if(n>=70)
			cout<<'C'<<endl;
		else if(n>=60)
			cout<<'D'<<endl;
		else if(n>=0)
			cout<<'E'<<endl;
		else
			cout<<"ERROR"<<endl;
	}
	return 0;
}
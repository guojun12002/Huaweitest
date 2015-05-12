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
		if(str.length()>=2)
			cout<<str.substr(1)<<endl;
	}
	return 0;
}
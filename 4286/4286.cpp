#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"


bool search(char* pw, int c)
{
	for(int i=0; i<c-2; ++i)
		if(pw[i] == pw[c] && pw[i+1] == pw[c+1] && pw[i+2] == pw[c+2]) return true;
	return false;
}
int main()
{
	freopen("input.txt", "r", stdin);
	char pw[100];
	while(cin >> pw)
	{
		int len = strlen(pw);
		if(len <= 8)
		{
			cout<<"NG"<<endl;
			continue;
		}
		int num[4] = {};
		for(int i=0; i<len; ++i)
			if(isdigit(pw[i])) num[0] = 1;
			else if(isupper(pw[i])) num[1] = 1;
			else if(islower(pw[i])) num[2] = 1;
			else num[3] = 1;
		if(num[0]+num[1]+num[2]+num[3] < 3)
		{
			cout<<"NG"<<endl;
			continue;
		}
		bool flag = false;
		for(int i=3; i<len-2; ++i)
			if(search(pw,i))
			{
				flag = true;
				break;
			}
		if(flag)
		{
			cout<<"NG"<<endl;
			continue;
		}
		cout<<"OK"<<endl;
	}
	return 0;
}
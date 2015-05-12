#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"


int main()
{
	freopen("input.txt", "r", stdin);
	char str[1000];
	gets(str);
	char* s = str;
	int x = 0, y = 0;
	while(s != NULL && *s != '\0')
	{
		if(*s == ';')
		{
			++s;
			continue;
		}
		int n = 0;
		char c = ' ';
		char* p = strchr(s, ';');
		if(p == NULL) break;
		bool flag = true;
		while(s != p)
		{
			if(isalpha(*s))
				if(flag)
				{
					c = *s;
					flag = false;
				}
				else
				{
					c = ' ';
					break;
				}
			else if(isdigit(*s))
				n = n * 10 + *s - '0';
			else
			{
				c = ' ';
				break;
			}
			++s;
		}
		switch(c)
		{
			case 'A': x -= n; break;
			case 'D': x += n; break;
			case 'W': y += n; break;
			case 'S': y -= n; break;
			default: break;
		}
		s = p;
	}
	cout<<x<<','<<y<<endl;
	return 0;
}
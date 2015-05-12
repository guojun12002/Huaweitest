#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;


int main()
{
	freopen("input.txt", "r", stdin);
	char str[100];
	while(gets(str) != NULL)
	{
		int len = strlen(str);
		for(int i=0; i<len; i++)
			if(isupper(str[i]))
				if(str[i] >= 'V' && str[i] <= 'Z')
					str[i] = tolower(str[i]) - 21;
				else if(str[i] >= 'A')
					str[i] = tolower(str[i]) + 5;
		puts(str);
	}
	return 0;
}
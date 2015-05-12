#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"

int MIN(int* n)
{
	int min = 10000;
	for(int i=1; i<26; ++i)
		if(min > n[i] && n[i] > 0) min = n[i];
	return min;
}

int main()
{
	freopen("input.txt", "r", stdin);
	char str[100];
	while(cin >> str)
	{
		int len = strlen(str);
		char s[100];
		int c[26] = {};
		int l = 0;
		for(int i=0; i<len; ++i)
		{
			if(c[str[i]-'a'] == 0) s[l++] = str[i];
			++c[str[i]-'a'];
		}
		s[l] = '\0';
		// cout<<s<<endl;
		int min = MIN(c);
		// cout<<min<<endl;
		for(int i=0; i<strlen(s); ++i)
			if(c[s[i]-'a'] > min)
				for(int j=0; j<c[s[i]-'a']; ++j)
					printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
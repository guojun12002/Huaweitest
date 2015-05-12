#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"

char password(char c)
{
	if(isupper(c))
		if(c == 'Z') return 'a';
		else return tolower(c) + 1;
	else if(islower(c))
		if(c >= 'a' && c <= 'c') return '2';
		else if(c >= 'd' && c <= 'f') return '3';
		else if(c >= 'g' && c <= 'i') return '4';
		else if(c >= 'j' && c <= 'l') return '5';
		else if(c >= 'm' && c <= 'o') return '6';
		else if(c >= 'p' && c <= 's') return '7';
		else if(c >= 't' && c <= 'v') return '8';
		else return '9';
	else
		return c;
}
int main()
{
	freopen("input.txt", "r", stdin);
	char str[105];
	while(cin >> str)
	{
		char pw[105];
		int len = strlen(str);
		for(int i=0; i<len; ++i)
			pw[i] = password(str[i]);
		pw[len] = '\0';
		cout<<pw<<endl;
	}
	return 0;
}
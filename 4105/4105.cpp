#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
// #include "source/"

string STR[6][2]={
	"reset", " ",
	"reset", "board",
	"board", "add",
	"board", "delet",
	"reboot", "backplane",
	"backplane", "abort"
};
string RES[7]={
	"reset what",
	"board fault",
	"where to add",
	"no board at all",
	"impossible",
	"install first",
	"unkown command"
};
void search(string& str1, string& str2)
{
	int fits = 0, c;
	bool fit[6][2] = {};
	for(int i=0; i<6; ++i)
	{
		if(STR[i][0].find(str1, 0) == 0)
			fit[i][0] = true;
		if(STR[i][1].find(str2, 0) == 0)
			fit[i][1] = true;
	}
	for(int i=0; i<6; ++i)
	{
		if(fit[i][0] && fit[i][1])
		{
			++fits;
			c = i;
		}
	}
	if(fits == 1)
		cout << RES[c] << endl;
	else
		cout << RES[6] << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	char str[1000];
	while(gets(str) != NULL)
	{
		string str1, str2;
		char *s = strchr(str, ' ');
		if(s == NULL)
		{
			str1.assign(str);
			str2.assign(" ");
		}
		else
		{
			str1.assign(str, s);
			str2.assign(s+1);
		}
		search(str1, str2);
	}
	return 0;
}
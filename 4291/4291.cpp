#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
// #include "source/"

struct ERROR
{
	char name[17];
	int line;
};
typedef vector<ERROR> VE;
typedef vector<int> Vi;
int search(VE& E, ERROR& e)
{
	for(int i=0; i<E.size(); ++i)
		if(strcmp(E[i].name, e.name) == 0 && E[i].line == e.line)
			return i;
	return -1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	char str[1000];
	int n=0;
	VE E;
	Vi nE;
	while(gets(str) != NULL)
	{
		if(strlen(str) == 0) continue;
		char* s = strrchr(str, ' ');
		if(s == NULL) continue;
		char* ts = s+1;
		bool flag = true;
		while(*ts != '\0')
			if(!isdigit(*ts))
			{
				flag = false;
				break;
			}
			else
				++ts;
		if(!flag) continue;
		int line = atoi(s+1);
		while(*s == ' ')
			--s;
		ts = strrchr(str, '\\');
		char* begin;
		if(ts == NULL)
			begin = str;
		else
			begin = ts+1;
		string name(begin, s+1);
		if(name.find(' ') != string::npos) continue;
		// cout<<name<<'-'<<line<<endl;
		ERROR file;
		if(name.length() <= 16)
			strcpy(file.name, name.c_str());
		else
		{
			for(int i=0; i<16; ++i)
				file.name[i] = name[name.length()-16+i];
			file.name[16] = '\0';
		}
		file.line = line;
		// cout<<file.name<<'-'<<file.line<<endl;
		int pos = search(E, file);
		// cout<<pos<<endl;
		if(pos != -1)
			nE[pos] += 1;
		else
		{
			if(n < 8)
				++n;
			else
			{
				E.erase(E.begin());
				nE.erase(nE.begin());
			}
			E.push_back(file);
			nE.push_back(1);

		}
	}
	for(int i=0; i<E.size(); ++i)
		cout<<E[i].name<<' '<<E[i].line<<' '<<nE[i]<<endl;
	return 0;
}


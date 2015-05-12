#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
// #include "source/"
int comp[256] = {};

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
//个子 1、对子 2、顺子（连续5张） 4、三个 3、炸弹（四个）5和对王 6
int checktype(string& s)
{
	switch(s.length())
	{
		case 11: return 6; //对王
		case 7: return 5;	//炸弹
		case 9: return 4;	//顺子
		case 5:	if(s[1]==' ') return 3;else return 1; //三个或者单王
		case 3: return 2;	//对子
		case 1: return 1;	//个子
	}
}
void pick1(string& str)
{
	int l = str.find("10", 0);
	while(l != string::npos)
	{
		str.erase(str.begin()+l);
		l = str.find("10", 0);
	}
}
void push1(string& str)
{
	int l = str.find("0", 0);
	while(l != string::npos)
	{
		str.insert(l, "1");
		l = str.find("0", l+2);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	char str[100];
	comp['3'] = 1;
	comp['4'] = 2;
	comp['5'] = 3;
	comp['6'] = 4;
	comp['7'] = 5;
	comp['8'] = 6;
	comp['9'] = 7;
	comp['0'] = 8;
	comp['J'] = 9;
	comp['Q'] = 10;
	comp['K'] = 11;
	comp['A'] = 12;
	comp['2'] = 13;
	while(gets(str) != NULL)
	{
		int mid = strchr(str, '-') - str;
		string str1(str, 0, mid);
		int l = str1.find("10", 0);
		pick1(str1);
		string str2(str, mid+1, strlen(str));
		pick1(str2);
		int type1 = checktype(str1);
		int type2 = checktype(str2);
		// cout<<str1<<endl<<str2<<endl;
		if(type1 == 6 || (type1 == 5 && type2 < 5))
		{
			push1(str1);
			cout << str1 << endl;
			continue;
		}
		else if(type2 == 6 || (type2 == 5 && type1 < 5))
		{
			push1(str2);
			cout << str2 << endl;
			continue;
		}
		else if(type1 == 1 && type2 == 1 && (str1.length() > 1 || str2.length() > 1))
		{
			if(str1.length() > 1 && str2.length() > 1)
				if(str1[0] == 'J')
					cout << str1 << endl;
				else
					cout << str2 << endl;
			else if(str1.length() > 1)
				cout << str1 << endl;
			else
				cout << str2 << endl;
			continue;
		}
		else if(type1 == type2)
		{
			if(comp[str1[str1.length()-1]] > comp[str2[str2.length()-1]])
			{
				push1(str1);
				cout << str1 << endl;
			}
			else
			{
				push1(str2);
				cout << str2 << endl;
			}
			continue;
		}
		else
			cout << "ERROR" << endl;
	}
	return 0;
}
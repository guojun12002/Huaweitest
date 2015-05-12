#include <stdlib.h>
#include <string.h>
#include "oj.h"
#include <string>
#include <set>
struct comp
{
	bool operator()(const string& s1, const string& s2)
	{
		// int len = s1.length() < s2.length() ? s1.length() : s2.length();
		// for(size_t i=0; i<len; ++i)
		// 	if(s1[i] != s2[i]) return s1[i] < s2[i];
		return s1+s2 < s2+s1;
	}
};
int  smallestDigit(int a[],int nCount,char * strRst)
{
	if(NULL == a || strRst == NULL) return -1;
	multiset<string, comp> str;
	for(int i=0; i<nCount; ++i)
	{
		string s;
		int n = a[i];
		while(n > 0)
		{
			s.insert(0, 1, n%10+'0');
			n /= 10;
		}
		str.insert(s);
	}
	string ss;
	for(multiset<string, comp>::iterator i = str.begin(); i != str.end(); ++i)
		ss += *i;
	strcpy(strRst, ss.c_str());
	return 0;
}
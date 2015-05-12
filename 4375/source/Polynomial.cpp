/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/9
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/9
Author      :
Modification: Created file

******************************************************************************/


/******************************************************************************************************
Description     : �������һԪ����ʽ������ͬ����ϲ������������һԪ����ʽ 
Prototype       : void OrderPolynomial (char* InputString, char* OutputString)
Input Param     : char* InputString �������ʽ�ַ���
Output Param    : char* OutputString �������ʽ�ַ���
Return Value    : void

********************************************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
char* cmp(char* s1, char* s2)
{
	if(NULL == s1) return s2;
	if(NULL == s2) return s1;
	return s1<s2?s1:s2;
}
void inttostring(string& s, int n)
{
	if(n == 0) s.push_back('0');
	while(n > 0)
	{
		s.insert(s.begin(), '0'+n%10);
		n /= 10;
	}
}
void OrderPolynomial (char* InputString, char* OutputString)
{
    /*������ʵ�ֹ���*/
	if(NULL == InputString || NULL == OutputString) return;
	char* s = InputString;
	map<int, int, greater<int> > m;
	while(s != NULL)
	{
		int a, b;
		sscanf(s, "%dX^%d", &a, &b);
		m[b] += a;
		char* s1 = strchr(s+1, '+');
		char* s2 = strchr(s+1, '-');
		s = cmp(s1, s2);
	}
	typedef map<int, int, greater<int> >::iterator mit;
	string str;
	for(mit i=m.begin(); i!=m.end(); ++i)
	{
		// cout<<i->second<<' '<<i->first<<endl;
		if(i->second < 0)
			str.push_back('-');
		else if(i->second > 0)
			str.push_back('+');
		else
			continue;
		string A, B;
		inttostring(A, abs(i->first));
		inttostring(B, abs(i->second));
		string t="X^";
		// str = str+B+t+A;
		str += B;
		str += t;
		str += A;
	}
	if(str[0] == '+') str.erase(str.begin());
	strcpy(OutputString, str.c_str());
    return;
}

#include <stdlib.h>
#include "oj.h"
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
int l = 0;
string str;
/*****************************************************************
功能:存储输入的字符创

输入:字符串

输出:无
     
返回:0表示成功,其它返回-1
****************************************************************/
int  AddString(char *strValue)
{
	if(NULL == strValue) return -1;
	int len = strlen(strValue);
	if(len == 0 || len > 100) return -1;
	str.append(strValue);
	if(len % 8 == 0)
		l += len/8;
	else
	{
		l += len/8+1;
		str.append((len/8+1)*8-len, '0');
	}
	return 0;
}

/****************************************************************
功能:获取补位后的二维数组的长度

输入:无

输出:无
     
返回:二维数组长度
******************************************************************/
int  GetLength()
{
	return l;
}

/*****************************************************************************
功能:将补位后的二维数组，与输入的二维数组做比较

输入:strInput:输入二维数组,iLen：输入的二维数组的长度

输出:无
     
返回:若相等,返回0;不相等,返回-1.其它:-1;
******************************************************************************/
int  ArrCmp(char strInput[][9],int iLen)
{
	if(iLen != l || strInput == NULL || iLen == 0) return -1;
	string s;
	for(int i=0; i<iLen; ++i)
		s.append(strInput[i]);
	// cout<<str<<endl<<s<<endl;
	if(str != s) return -1;
	str.clear();
	l = 0;
	return 0;
}
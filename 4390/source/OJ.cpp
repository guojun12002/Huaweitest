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
����:�洢������ַ���

����:�ַ���

���:��
     
����:0��ʾ�ɹ�,��������-1
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
����:��ȡ��λ��Ķ�ά����ĳ���

����:��

���:��
     
����:��ά���鳤��
******************************************************************/
int  GetLength()
{
	return l;
}

/*****************************************************************************
����:����λ��Ķ�ά���飬������Ķ�ά�������Ƚ�

����:strInput:�����ά����,iLen������Ķ�ά����ĳ���

���:��
     
����:�����,����0;�����,����-1.����:-1;
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
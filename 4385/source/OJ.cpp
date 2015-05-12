#include <stdlib.h>
#include "oj.h"


/*
����:
	����һ��������5λ��������
	Ҫ��:
		1��������Ǽ�λ�� 
		2���ֱ����ÿһλ���� 
		3�������������λ���֣�����ԭ��Ϊ321,Ӧ���123
����:
	���� iInput,λ��������5������

���:
    ����λ��		iNum
	�ո���������    strRst
	��������		iOutput

����:
	0  �ɹ�
	-1 ������Ч
*/

int ProcessX(int iInput, int& iNum, char * strRst, int& iOutput)
{
	if(iInput > 99999 || iInput < -99999) return -1;
	if(strRst == NULL) return -1;
	if(iInput == 0)
	{
		iNum = 1;
		strRst[0] = '0';
		strRst[1] = '\0';
		iOutput = 0;
		return 0;
	}
	bool flag = false;
	iNum = 0;
	iOutput = 0;
	if(iInput < 0)
	{
		flag = true;
		iInput = abs(iInput);
	}
	int str[10];
	while(iInput > 0)
	{
		str[iNum] = iInput % 10;
		iInput /= 10;
		++iNum;
	}
	char* s = strRst;
	if(flag)
	{
		*s = '-';
		++s;
	}
	for(int i=0; i<iNum; ++i)
	{
		*s = str[iNum-i-1] + '0';
		++s;
		if(i != iNum-1)
		{
			*s = ' ';
			++s;
		}
	}
	*s = '\0';
	for(int i=0; i<iNum; ++i)
		iOutput = iOutput * 10 + str[i];
	if(flag) iOutput = 0 - iOutput;
	return 0;
}
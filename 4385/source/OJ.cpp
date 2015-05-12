#include <stdlib.h>
#include "oj.h"


/*
功能:
	给出一个不多于5位的整数，
	要求:
		1、求出它是几位数 
		2、分别输出每一位数字 
		3、按逆序输出各位数字，例如原数为321,应输出123
输入:
	整型 iInput,位数不大于5的整数

输出:
    整数位数		iNum
	空格间隔输出结果    strRst
	逆序整数		iOutput

返回:
	0  成功
	-1 输入无效
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
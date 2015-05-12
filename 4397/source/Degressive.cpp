/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 
Last Modified :
Description   :
Function List :

History       :
1.Date        : 
Author      :
Modification: Created file

******************************************************************************/
#include "Degressive.h"
//给出一个非负整数，找到这个非负整数中包含的最大递减数。一个数字的递减数是指相邻的数位从大到小排列的数字。
//如： 95345323，递减数有：953,95,53,53,532,32, 那么最大的递减数为953。
//如果输入的数字为负数，返回-1。
void inttostr(string& str, int n)
{
	if(n == 0)
		str = "0";
	else
		while(n>0)
		{
			str.insert(str.begin(), '0'+n%10);
			n /= 10;
		}
}
int getMaxDegressiveNum (int num)
{
    // your code here...
	if(num < 0) return -1;
	string str;
	inttostr(str, num);
	int n = str[0]-'0';
	int max = n;
	for(int i=1; i<str.length(); ++i)
	{
		if(str[i] < str[i-1])
			n = n*10+str[i]-'0';
		else
			n = str[i]-'0';
		if(max < n) max = n;
	}
	return max;
}

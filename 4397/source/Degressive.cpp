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
//����һ���Ǹ��������ҵ�����Ǹ������а��������ݼ�����һ�����ֵĵݼ�����ָ���ڵ���λ�Ӵ�С���е����֡�
//�磺 95345323���ݼ����У�953,95,53,53,532,32, ��ô���ĵݼ���Ϊ953��
//������������Ϊ����������-1��
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

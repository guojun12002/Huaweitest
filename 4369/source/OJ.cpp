#include <stdlib.h>
#include <cmath>
#include "oj.h"

// 功能：判断输入 nValue 是否为水仙花数
// 输入： nValue为正整数
// 输出：无
// 返回：如果输入为水仙花数，返回1，否则返回0
unsigned int IsDaffodilNum(unsigned int  nValue)
{
	int str[100];
	int n = 0;
	unsigned int num = nValue;
	while(num > 0)
	{
		str[n++] = num % 10;
		num = num / 10;
	}
	unsigned int sum = 0;
	for(int i=0; i<n; ++i)
		sum += pow(str[i]*1.0, n*1.0);
	if(sum == nValue) return 1;
	return 0;
}


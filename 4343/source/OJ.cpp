
#include "OJ.h"

/*
功能: 求n(n ≤ 65536)以内的所有阿姆斯特朗数
原型：
    int CalcArmstrongNumber(int n);

输入参数：
    int n: n ≤ 65536

返回值：
    n以内的阿姆斯特朗数的数量。
*/

int CalcArmstrongNumber(int n)
{
    /*在这里实现功能*/
	int sum = 0;
	for(int i=2; i<=n; ++i)
	{
		int num = i;
		int s[10];
		int l = 0;
		int x = 0;
		while(num > 0)
		{
			s[l++] = num % 10;
			num /= 10;
		}
		for(int j=0; j<l; ++j)
			x += s[j] * s[j] * s[j];
		if(x == i) ++sum;
	}
    return sum;
}

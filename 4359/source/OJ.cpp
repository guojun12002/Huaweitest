
#include "OJ.h"

/*
Description  
         给定一个unsigned int型的正整数，求其二进制表示中“1”的个数，要求算法的执行效率尽可能地高。
Prototype
         int GetCount(unsigned int num)
Input Param 
         num     给定的正整数
Output Param 
         无
Return Value
         返回1的个数
*/
int GetCount(unsigned int num)
{
	/*在这里实现功能*/
	int n = 0;
	while(num > 0)
	{
		if(num % 2 == 1) ++n;
		num /= 2;
	}
	return n;
}

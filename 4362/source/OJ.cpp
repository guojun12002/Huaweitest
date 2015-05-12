
#include "OJ.h"

/*
Description  
         取给定正整数的指定bit位开始的指定长度的数据。bit位从右向左从0开始计算。
Prototype
         unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
Input Param 
         input      输入的整数
         startbit   需要获取的开始bit
         bitlen     需要获取的bit长度
Output Param 
         无
Return Value
		 对应的bit取值
*/

unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
{
	/*在这里实现功能*/
	int bit[100] = {};
	int n = 0;
	while(input > 0)
	{
		bit[n++] = input % 2;
		input /= 2;
	}
	n = 0;
	for(int i=startbit; i>startbit-bitlen; --i)
		n = n * 2 + bit[i];
	return n;
}


#include "OJ.h"

/*
Description  
         ȡ������������ָ��bitλ��ʼ��ָ�����ȵ����ݡ�bitλ���������0��ʼ���㡣
Prototype
         unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
Input Param 
         input      ���������
         startbit   ��Ҫ��ȡ�Ŀ�ʼbit
         bitlen     ��Ҫ��ȡ��bit����
Output Param 
         ��
Return Value
		 ��Ӧ��bitȡֵ
*/

unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
{
	/*������ʵ�ֹ���*/
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


#include "OJ.h"

/*
Description  
         ����һ��unsigned int�͵�����������������Ʊ�ʾ�С�1���ĸ�����Ҫ���㷨��ִ��Ч�ʾ����ܵظߡ�
Prototype
         int GetCount(unsigned int num)
Input Param 
         num     ������������
Output Param 
         ��
Return Value
         ����1�ĸ���
*/
int GetCount(unsigned int num)
{
	/*������ʵ�ֹ���*/
	int n = 0;
	while(num > 0)
	{
		if(num % 2 == 1) ++n;
		num /= 2;
	}
	return n;
}

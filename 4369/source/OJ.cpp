#include <stdlib.h>
#include <cmath>
#include "oj.h"

// ���ܣ��ж����� nValue �Ƿ�Ϊˮ�ɻ���
// ���룺 nValueΪ������
// �������
// ���أ��������Ϊˮ�ɻ���������1�����򷵻�0
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

